#include "lexer.h"

int isKeyword(char buffer[])
{
    for (int i = 0; i < 32; i++)
        if (strcmp(keywords[i], buffer) == 0)
            return 1;
    return 0;
}

void handleKeywords(FILE *fp, char *buffer, char ch)
{
    int i = 0;
    buffer[i++] = ch;

    while ((ch = fgetc(fp)) != EOF && (isalnum(ch) || ch == '_'))
    {
        buffer[i++] = ch;
        currentCol++;
    }

    buffer[i] = '\0';

    if (isKeyword(buffer))
        printf("Keyword : %s\n", buffer);
    else
        printf("Identifier : %s\n", buffer);

    if (ch != EOF)
        ungetc(ch, fp);
}

