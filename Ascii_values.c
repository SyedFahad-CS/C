#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    scanf(" %c", &ch);
    printf("ASCII value of '%c' is %d\n\n", ch, ch);
    printf("Printable characters and their ASCII codes:\n");
    for (int i = 32; i <= 126; i++) {
        printf("%c : %d\n", i, i);
    }
    return 0;
}
