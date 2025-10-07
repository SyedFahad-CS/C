#include <stdio.h>
#include <limits.h>
int main() {
 int a, b;
 printf("Enter two integers: ");
 scanf("%d %d", &a, &b);
 // Detect overflow in addition
 if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b)) {
 printf("Overflow detected in addition!\n");
 } else {
 printf("Addition result: %d\n", a + b);
 }
 // Detect overflow in subtraction
 if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b)) {
 printf("Overflow detected in subtraction!\n");
 } else {
 printf("Subtraction result: %d\n", a - b);
 }
 // Detect overflow in multiplication
 if (a != 0 && (a * b) / a != b) {
 printf("Overflow detected in multiplication!\n");
 } else {
 printf("Multiplication result: %d\n", a * b);
 }
 return 0;
}