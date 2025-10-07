#include<stdio.h>
int globalVar=1999;
int main(){
    int localVar = 20;
    printf("\n--- Program 3: Scope Rules ---\n");
    printf("Global Variable: %d\n", globalVar);
    printf("Local Variable: %d\n", localVar);
    {
        int blockVar = 30;
        printf("Block Variable: %d\n", blockVar);
    }
    return 0;
}