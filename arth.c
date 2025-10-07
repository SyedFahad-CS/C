#include<stdio.h>
#define PI 3.14
void main() {
    float radius, height;
    printf("\n--- Program 5: Constants and Arithmetic ---\n");
    printf("Enter radius of cylinder: ");
    scanf("%f", &radius);
    printf("Enter height of cylinder: ");
    scanf("%f", &height);
    float volume = PI * radius * radius * height;
    printf("Volume of cylinder: %.2f\n", volume);
}