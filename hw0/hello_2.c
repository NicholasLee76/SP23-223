#include <stdio.h>

int main() {
	char ans[126];
	printf("Enter your name: ");
    scanf("%[^\n]s", ans);
    printf("Hello, %s!\n", ans);
}
