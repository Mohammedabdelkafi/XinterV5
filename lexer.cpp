#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKENS 256
#define TOKEN_NUMBER 1
#define TOKEN_PLUS 2
#define TOKEN_MINUS 3
#define TOKEN_MULTIPLY 4
#define TOKEN_DIVIDE 5
#define TOKEN_LPAREN 6
#define TOKEN_RPAREN 7
#define TOKEN_EOF 8
#define TOKEN_INVALID 9

char input_text[256];
int pos;
char current_char;
char token_value[256]; // Buffer to hold token values

typedef struct {
    int type;
    char value[256];
} Token;

Token tokens[MAX_TOKENS];
int token_count = 0;

void init_lexer(char* text) {
    strncpy(input_text, text, 255);
    input_text[255] = '\0';
    pos = 0;
    current_char = input_text[pos];
}

void advance() {
    pos++;
    if (pos > strlen(input_text) - 1) {
        current_char = '\0';
    } else {
        current_char = input_text[pos];
    }
}

void skip_whitespace() {
    while (current_char != '\0' && isspace(current_char)) {
        advance();
    }
}

void create_token(int type, char* value) {
    tokens[token_count].type = type;
    strncpy(tokens[token_count].value, value, 255);
    tokens[token_count].value[255] = '\0';
    token_count++;
}

void get_number() {
    int start_pos = pos;
    while (current_char != '\0' && isdigit(current_char)) {
        advance();
    }
    int len = pos - start_pos;
    strncpy(token_value, input_text + start_pos, len);
    token_value[len] = '\0';
    create_token(TOKEN_NUMBER, token_value);
}

void get_next_token() {
    while (current_char != '\0') {
        if (isspace(current_char)) {
            skip_whitespace();
            continue;
        }

        if (isdigit(current_char)) {
            get_number();
            return;
        }

        if (current_char == '+') {
            advance();
            create_token(TOKEN_PLUS, "+");
            return;
        }

        if (current_char == '-') {
            advance();
            create_token(TOKEN_MINUS, "-");
            return;
        }

        if (current_char == '*') {
            advance();
            create_token(TOKEN_MULTIPLY, "*");
            return;
        }

        if (current_char == '/') {
            advance();
            create_token(TOKEN_DIVIDE, "/");
            return;
        }

        if (current_char == '(') {
            advance();
            create_token(TOKEN_LPAREN, "(");
            return;
        }

        if (current_char == ')') {
            advance();
            create_token(TOKEN_RPAREN, ")");
            return;
        }

        char invalid_char[2] = {current_char, '\0'};
        create_token(TOKEN_INVALID, invalid_char);
        return;
    }

    create_token(TOKEN_EOF, "");
}

void print_tokens() {
    printf("Tokens:\n");
    for (int i = 0; i < token_count; i++) {
        printf("Token(Type: %d, Value: %s)\n", tokens[i].type, tokens[i].value);
    }
}

int main() {
    printf("Enter a mathematical expression: ");
    fgets(input_text, sizeof(input_text), stdin);
    input_text[strcspn(input_text, "\n")] = '\0'; // Remove the trailing newline character

    init_lexer(input_text);

    do {
        get_next_token();
    } while (tokens[token_count - 1].type != TOKEN_EOF);

    print_tokens();

    return 0;
}
