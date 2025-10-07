#include<stdio.h>
int sumOfTwo(int x,int y){
    return x+y;
}
int multiplyOfTwo(int x,int y){
    return x*y;
}
void hello_World(void){
    printf("\nHello,World");
}
int main(void){
    printf("The sum of x and y is :%d",sumOfTwo(12,15));
    hello_World();
    char a='A';
    printf("%d",a);
    printf("The size of int is %d bytes",sizeof(a));
    return 0;
}
