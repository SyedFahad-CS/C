

#include <stdio.h>
void swap(int *x, int *y) {
    if (x != y) { // Check if the pointers are not the same
        *x = *x ^ *y; // Step 1: XOR x and y and store in x
        *y = *x ^ *y; // Step 2: XOR new x with y to get original x
        *x = *x ^ *y; // Step 3: XOR new x with new y to get original y
        printf("After Swapping X: %d Y:%d",*x,*y);
    }
}
int main() {
    int a, b;
    printf("Enter two integers (a and b): ");
    scanf("%d %d", &a, &b);
    printf("Before swapping: a = %d, b = %d\n", a, b);
    a = a + b; 
    b = a - b;
    a = a - b;
    printf("After swapping: a = %d, b = %d\n", a, b);
    return 0;
}
// Function to swap two integers without using a temporary variable and avoiding overflow
//how does XOR swapping work?
// XOR swapping works by using the properties of the XOR bitwise operation. The key properties are:
// 1. x ^ x = 0 (XORing a number with itself results in 0)
// 2. x ^ 0 = x (XORing a number with 0 results in the number itself)
// 3. XOR is commutative and associative, meaning the order of operations does not matter.
// The XOR swap algorithm uses these properties to swap two variables without a temporary variable:
// X=X ^ Y  (Now X holds the XOR of both numbers)
// Y=X ^ Y  (Now Y is original X)
// X=X ^ Y  (Now X is original Y)
// This method avoids overflow issues that can occur with arithmetic swapping (using addition and subtraction) when dealing with large integers.

