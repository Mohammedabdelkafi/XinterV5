#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char sourceCode[256];
char letters[] = "azertyuiopqsdfghjklmwxcvbnAZERTYUIOPQSDFGHJKLMWXCVBN";
char digits[] = "12345678890";
char BinOP[] = "+-/*";
char curr_char;
int pos = -1;
bool string = false;
bool integer = false;
char tokens[256][256];
int token_count = 0;

void input() {
    printf("Xinter > ");
    scanf("%s", sourceCode);
}

void advance() {
    pos++;
    curr_char = sourceCode[pos];
}

void append_token(const char* token) {
    strcpy(tokens[token_count], token);
    token_count++;
}

void tokenize() {
    while (sourceCode[pos] != '\0') {
        advance();
        switch (curr_char) {
            case '+':
                append_token("PLUS");
                break;
            case '-':
                append_token("MINUS");
                break;
            case '/':
                append_token("DIV");
                break;
            case '*':
                append_token("MUL");
                break;
            default:
                // Handle other characters or skip them
                break;
        }
    }
}

int main() {
    input();
    tokenize();
    
    // Print tokens for verification
    for (int i = 0; i < token_count; i++) {
        printf("Token: %s\n", tokens[i]);
    }

    return 0;
}
