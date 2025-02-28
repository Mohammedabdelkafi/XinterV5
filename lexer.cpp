#include <stdio.h>
char src[256];
int advance();
int pos = -1;
char CC[256];
int main() {
	printf("Xinter ===>");
	scanf("%s", &src);
	printf("%s", src);
	return 0;
}
int advance() {
	pos++;
	char CC[] = src[pos];
}
