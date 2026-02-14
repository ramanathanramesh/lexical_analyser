#include "lexer.h"

int currentLine = 1;
int currentCol  = 1;

/* bracket counters */
int lparen = 0, rparen = 0;
int lbrace = 0, rbrace = 0;
int lbracket = 0, rbracket = 0;

/* keywords */
char *keywords[] = {
    "auto","break","case","char","const","continue","default","do",
    "double","else","enum","extern","float","for","goto","if",
    "int","long","register","return","short","signed","sizeof",
    "static","struct","switch","typedef","union","unsigned",
    "void","volatile","while"
};

/* operators */
char op1[] = "+-*/%=<>!";
char *op2[] = {"==","!=","<=",">=","++","--","&&","||"};

int main(int argc, char *argv[])
{
    FILE *fp;
    char ch, buffer[MAX_LEN];

    if (argc != 2)
    {
        printf("Usage: ./lexer <file.c>\n");
        return 1;
    }

    fp = fopen(argv[1], "r");
    if (!fp)
    {
        printf("File open error\n");
        return 1;
    }

    printf("===== LEXICAL ANALYSIS START =====\n\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        /* SKIP PREPROCESSOR LINES (#include etc.) */
        if (ch == '#')
        {
            while ((ch = fgetc(fp)) != '\n' && ch != EOF);
            currentLine++;
            currentCol = 1;
            continue;
        }

        if (ch == '\n')
        {
            currentLine++;
            currentCol = 1;
            continue;
        }

        if (isspace(ch))
        {
            currentCol++;
            continue;
        }

        if (isalpha(ch) || ch == '_')
            handleKeywords(fp, buffer, ch);

        else if (isdigit(ch))
            handleDigit(fp, buffer, ch);

        else if (ch == '"')
            validStringLiteral(fp, buffer, ch);

        else if (ch == '\'')
            validCharLiteral(fp, buffer, ch);

        else if (isOperator(ch))
            handleOperators(fp, buffer, ch);

        else if (strchr("(){}[];,", ch))
            handleDelimiter(ch);

        else
            printf("Lexical Error at line %d, col %d: '%c'\n",
                   currentLine, currentCol, ch);

        currentCol++;
    }

    checkUnmatchedBrackets();

    printf("\n===== LEXICAL ANALYSIS END =====\n");
    fclose(fp);
    return 0;
}
