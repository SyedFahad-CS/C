#include<stdio.h>
int main() {
    float celsius, fahrenheit;
    printf("\n--- Program 6: Temperature Conversion ---\n");
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    // Celsius to Fahrenheit
    fahrenheit = (celsius * 9.0 / 5.0) + 32;
    printf("%.2f C = %.2f F\n", celsius, fahrenheit);
    // Fahrenheit to Celsius
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5.0 / 9.0;
    printf("%.2f F = %.2f C\n", fahrenheit, celsius);
    return 0;
}