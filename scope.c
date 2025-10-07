#include <stdio.h>
// Global variable
int globalVar = 10;
int main() {
    int localVar = 20; // Local variable
    printf("Global Variable: %d\n", globalVar);
    printf("Local Variable: %d\n", localVar);
    {
        int blockVar = 30; // Block scope variable
        printf("Block Variable: %d\n", blockVar);
        printf("Access Global in block: %d\n", globalVar);
    }
    // blockVar is not accessible here
    // printf("%d", blockVar); // Uncommenting this will cause an error.
    return 0;
}
