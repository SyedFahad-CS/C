#include <stdio.h>
#define PI 3.14159  // Symbolic constant using #define
int main() {
    const float g = 9.81;  // Constant using const keyword
    float radius, height;
    printf("Enter radius of cylinder: ");
    scanf("%f", &radius);
    printf("Enter height of cylinder: ");
    scanf("%f", &height);
    float volume = PI * radius * radius * height; // Volume calculation
    float weight = volume * g; // Example using another constant
    printf("Volume of cylinder: %.2f\n", volume);
    printf("Weight (assuming density=1): %.2f\n", weight);
    return 0;
}
