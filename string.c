#include "lexer.h"

void validStringLiteral(FILE *fp, char buffer[], char ch)
{
    int i = 0;

    while ((ch = fgetc(fp)) != EOF && ch != '"')
    {
        if (ch == '\n')
        {
            printf("Lexical Error at line %d: Unterminated string\n", currentLine);
            return;
        }
        buffer[i++] = ch;
    }

    buffer[i] = '\0';
    printf("String Literal : \"%s\"\n", buffer);
}


void validCharLiteral(FILE *fp, char buffer[], char ch)
{
    char c1, c2;

    c1 = fgetc(fp);   // character inside quotes
    c2 = fgetc(fp);   // should be closing '

    // Check for end of file or newline
    if (c1 == EOF || c1 == '\n' || c2 == EOF || c2 == '\n')
    {
        printf("Lexical Error at line %d: Invalid char literal\n", currentLine);
        return;
    }

    // Closing quote missing
    if (c2 != '\'')
    {
        printf("Lexical Error at line %d: Invalid char literal\n", currentLine);

        // Skip until closing ' or newline (error recovery)
        while (c2 != '\'' && c2 != '\n' && c2 != EOF)
            c2 = fgetc(fp);

        return;
    }

    // Valid character literal
    printf("Character Literal : '%c'\n", c1);
}
