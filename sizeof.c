#include<stdio.h>
int main(void){
    int a=10;
    float b=3.14;
    double c=3.141592653589793;
    char d='A';
    // bool e=1;
    printf("The size of int is %d bytes\n",sizeof(a));
    printf("The size of float is %d bytes\n",sizeof(b));

 
    printf("The size of double is %d bytes\n",sizeof(c));
    printf("The size of char is %d bytes\n",sizeof(d));
    printf("He is such a crzy bully");
    // printf("The size of bool is %d bytes\n",sizeof(e));
}