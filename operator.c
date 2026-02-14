#include "lexer.h"

int isOperator(char ch)
{
    return strchr(op1, ch) != NULL;
}

int isDualOperator(char buffer[])
{
    for (int i = 0; i < 8; i++)
        if (strcmp(op2[i], buffer) == 0)
            return 1;
    return 0;
}

void handleOperators(FILE *fp, char buffer[], char ch)
{
    int i = 0;
    buffer[i++] = ch;

    char next = fgetc(fp);
    if (next == EOF)
    {
        printf("Operator : %c\n", ch);
        return;
    }

    buffer[i++] = next;
    buffer[i] = '\0';

    if (isDualOperator(buffer))
        printf("Operator : %s\n", buffer);
    else
    {
        printf("Operator : %c\n", ch);
        ungetc(next, fp);
    }
}
