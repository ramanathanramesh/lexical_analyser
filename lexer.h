#ifndef LEXER_H
#define LEXER_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 100

/* line & column */
extern int currentLine;
extern int currentCol;

/* keyword list */
extern char *keywords[];

/* operator tables */
extern char op1[];
extern char *op2[];

/* bracket counters */
extern int lparen, rparen;
extern int lbrace, rbrace;
extern int lbracket, rbracket;

/* identifier */
int isKeyword(char buffer[]);
void handleKeywords(FILE *fp, char *buffer, char ch);

/* digit */
void handleDigit(FILE *fp, char *buffer, char ch);
void handleHex(FILE *fp, char *buffer, char prefix);
void handleOctal(FILE *fp, char *buffer, char prefix);
void handleBinary(FILE *fp, char *buffer, char prefix);
void handleDecimal(FILE *fp, char *buffer, char ch);

/* string & char */
void validStringLiteral(FILE *fp, char buffer[], char ch);
void validCharLiteral(FILE *fp, char buffer[], char ch);

/* operators */
int isOperator(char ch);
int isDualOperator(char buffer[]);
void handleOperators(FILE *fp, char buffer[], char ch);

/* delimiters / brackets */
void handleDelimiter(char ch);
void checkUnmatchedBrackets(void);

#endif
