#include<stdio.h>
int main(void){
    int x,y,sum=0,diff=0,multiply=1,divi,modulus;
    printf("Enter the value of X:");
    scanf("%d",&x);
    printf("\nEnter the value of Y:");
    scanf("%d",&y);
    sum=x+y;
    diff=x-y;
    multiply=x*y;
    divi=x/y;
    modulus=x%y;
    printf("\nThe sum of %d and %d is : %d",x,y,sum);
    printf("\nThe difference of %d and %d is : %d",x,y,diff);
    printf("\nThe multiplication result of %d and %d is : %d",x,y,multiply);
    printf("\nThe division result of %d and %d is : %d",x,y,divi);
    printf("\nThe modulus result of %d and %d is : %d",x,y,modulus);
}