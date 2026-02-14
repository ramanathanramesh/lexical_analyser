#include "lexer.h"

void handleHex(FILE *fp, char *buffer, char prefix)
{
    int i = 0;
    char ch;

    buffer[i++] = '0';
    buffer[i++] = prefix;

    while ((ch = fgetc(fp)) != EOF && isxdigit(ch))
    {
        buffer[i++] = ch;
        currentCol++;
    }

    buffer[i] = '\0';

    if (i == 2)
        printf("Lexical Error at line %d: Hex missing digits\n", currentLine);
    else
        printf("Hex Number : %s\n", buffer);

    if (ch != EOF) ungetc(ch, fp);
}

void handleOctal(FILE *fp, char *buffer, char prefix)
{
    int i = 0;
    char ch;

    buffer[i++] = '0';
    buffer[i++] = prefix;

    while ((ch = fgetc(fp)) != EOF && ch >= '0' && ch <= '7')
    {
        buffer[i++] = ch;
        currentCol++;
    }

    buffer[i] = '\0';

    if (i == 2)
        printf("Lexical Error at line %d: Octal missing digits\n", currentLine);
    else
        printf("Octal Number : %s\n", buffer);

    if (ch != EOF) ungetc(ch, fp);
}

void handleBinary(FILE *fp, char *buffer, char prefix)
{
    int i = 0;
    char ch;

    buffer[i++] = '0';
    buffer[i++] = prefix;

    while ((ch = fgetc(fp)) != EOF && (ch == '0' || ch == '1'))
    {
        buffer[i++] = ch;
        currentCol++;
    }

    buffer[i] = '\0';

    if (i == 2)
        printf("Lexical Error at line %d: Binary missing digits\n", currentLine);
    else
        printf("Binary Number : %s\n", buffer);

    if (ch != EOF) ungetc(ch, fp);
}

void handleDecimal(FILE *fp, char *buffer, char ch)
{
    int i = 0, dot = 0;
    buffer[i++] = ch;

    while ((ch = fgetc(fp)) != EOF)
    {
        if (isdigit(ch))
            buffer[i++] = ch;
        else if (ch == '.' && !dot)
        {
            dot = 1;
            buffer[i++] = ch;
        }
        else
            break;
    }

    buffer[i] = '\0';

    if (dot)
        printf("Decimal Number : %s\n", buffer);
    else
        printf("Integer Number : %s\n", buffer);

    if (ch != EOF) ungetc(ch, fp);
}

void handleDigit(FILE *fp, char *buffer, char ch)
{
    if (ch == '0')
    {
        char next = fgetc(fp);

        if (next == 'x' || next == 'X') { handleHex(fp, buffer, next); return; }
        if (next == 'o' || next == 'O') { handleOctal(fp, buffer, next); return; }
        if (next == 'b' || next == 'B') { handleBinary(fp, buffer, next); return; }

        ungetc(next, fp);
    }

    handleDecimal(fp, buffer, ch);
}
