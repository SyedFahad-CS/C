
#include <stdio.h>
#include <math.h>

int reverseNum(int num) {
    // Base case: single-digit number
    if (num < 10)
        return num;
        // Find number of digits
        int digits = (int)log10(num);
        // printf("%d",digits);
        // Move last digit to front and recurse for remaining number
        return (num % 10) * pow(10, digits) + reverseNum(num / 10);
        //easy way to do this?
    }
    int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Reversed number: %d\n", reverseNum(num));
    return 0;
}
// #include <stdio.h>
// int main() {
//     int num, rev = 0, digit;
//     printf("Enter a number: ");
//     scanf("%d", &num);
//     while (num != 0) {
//         digit = num % 10;       // Get the last digit
//         rev = rev * 10 + digit; // Add digit to reversed number
//         num = num/10;              // Remove the last digit
//     }
//     printf("Reversed number: %d\n", rev);
//     return 0;
// }