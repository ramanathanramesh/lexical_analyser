#include "lexer.h"

void handleDelimiter(char ch)
{
    switch (ch)
    {
        case '(':
            lparen++;
            printf("Delimiter : (\n");
            break;
        case ')':
            rparen++;
            if (rparen > lparen)
                printf("ERROR at line %d: Unmatched ')'\n", currentLine);
            else
                printf("Delimiter : )\n");
            break;

        case '{':
            lbrace++;
            printf("Delimiter : {\n");
            break;
        case '}':
            rbrace++;
            if (rbrace > lbrace)
                printf("ERROR at line %d: Unmatched '}'\n", currentLine);
            else
                printf("Delimiter : }\n");
            break;

        case '[':
            lbracket++;
            printf("Delimiter : [\n");
            break;
        case ']':
            rbracket++;
            if (rbracket > lbracket)
                printf("ERROR at line %d: Unmatched ']'\n", currentLine);
            else
                printf("Delimiter : ]\n");
            break;

        default:
            printf("Delimiter : %c\n", ch);
    }
}

void checkUnmatchedBrackets(void)
{
    if (lparen > rparen)
        printf("ERROR: %d unmatched '('\n", lparen - rparen);

    if (lbrace > rbrace)
        printf("ERROR: %d unmatched '{'\n", lbrace - rbrace);

    if (lbracket > rbracket)
        printf("ERROR: %d unmatched '['\n", lbracket - rbracket);
}
