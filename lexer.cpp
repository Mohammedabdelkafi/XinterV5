#include <stdio.h>
#include <string.h>
int tokenize();
int advance();
char a[10000];
int pos = -1;
char curr_char;
int main() {
    printf("===>");
    scanf("%s", a);
    printf("%s\n", a);
	return 0;
}
advance() {
	pos++;
}
tokenize() {
	
}
