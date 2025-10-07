#include <stdio.h>

int sum_of_digits(int n) {
    int sum = 0;
    n = (n < 0) ? -n : n;
    while (n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int main() {
    int num = -12345;
    printf("Sum of digits of %d is %d\n", num, sum_of_digits(num));
    return 0;
}
