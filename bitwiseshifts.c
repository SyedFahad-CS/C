#include<stdio.h>
void leftshift(int num, int shift) {
    int result = num << shift;
    printf("Left Shift: %d << %d = %d\n", num, shift, result);
}
int main(void) {
    int number, shift_amount;
    printf("Enter an integer: ");
    scanf("%d", &number);
    printf("Enter number of positions to left shift: ");
    scanf("%d", &shift_amount);
    leftshift(number, shift_amount);
    return 0;
}