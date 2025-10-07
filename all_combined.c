#include <stdio.h>
#include <limits.h>
#include <float.h>
#define PI 3.14159

// 1. Basic structure: Print student details
void program1() {
    char name[50];
    int roll;
    float marks;
    printf("\n--- Program 1: Student Details ---\n");
    printf("Enter name: ");
    scanf("%49s", name);
    printf("Enter roll number: ");
    scanf("%d", &roll);
    printf("Enter marks: ");
    scanf("%f", &marks);
    printf("\n--- Student Details ---\n");
    printf("Name: %s\nRoll Number: %d\nMarks: %.2f\n", name, roll, marks);
}
// 2. Character set and ASCII values
void program2() {
    char ch;
    printf("\n--- Program 2: ASCII Values ---\n");
    printf("Enter a character: ");
    scanf(" %c", &ch);
    printf("ASCII value of '%c' is %d\n\n", ch, ch);

    printf("Printable characters and their ASCII codes:\n");
    for (int i = 32; i <= 126; i++) {
        printf("%c : %d\n", i, i);
    }
}
// 3. Identifiers, Reserved Words, and Scope
int globalVar = 10;
void program3() {
    int localVar = 20;
    printf("\n--- Program 3: Scope Rules ---\n");
    printf("Global Variable: %d\n", globalVar);
    printf("Local Variable: %d\n", localVar);
    {
        int blockVar = 30;
        printf("Block Variable: %d\n", blockVar);
    }
}
// 4. Data types and sizeof()
void program4() {
    // --- Sizes of data types ---
    printf("\n--- Program 4: Data Types and sizeof() ---\n");
    printf("== Sizes of Data Types ==\n");
    printf("char        : %zu bytes\n", sizeof(char));
    printf("short       : %zu bytes\n", sizeof(short));
    printf("int         : %zu bytes\n", sizeof(int));
    printf("long        : %zu bytes\n", sizeof(long));
    printf("long long   : %zu bytes\n", sizeof(long long));
    printf("float       : %zu bytes\n", sizeof(float));
    printf("double      : %zu bytes\n", sizeof(double));
    printf("long double : %zu bytes\n", sizeof(long double));   
    // --- Ranges of data types ---
    printf("\n=== Ranges of Data Types ===\n");
    printf("char        : %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("int         : %d to %d\n", INT_MIN, INT_MAX);
    printf("long        : %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("float       : %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double      : %e to %e\n", DBL_MIN, DBL_MAX);
    printf("long double : %Le to %Le\n", LDBL_MIN, LDBL_MAX);
}

// 5. Constants and arithmetic expressions
void program5() {
    float radius, height;
    printf("\n--- Program 5: Constants and Arithmetic ---\n");
    printf("Enter radius of cylinder: ");
    scanf("%f", &radius);
    printf("Enter height of cylinder: ");
    scanf("%f", &height);
    float volume = PI * radius * radius * height;
    printf("Volume of cylinder: %.2f\n", volume);
}
// 6. Temperature conversion
void program6() {
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
}
int main() {
    int choice;
    do {
        printf("\n===== MENU =====\n");
        printf("1. Student Details\n");
        printf("2. ASCII Values\n");
        printf("3. Scope Rules\n");
        printf("4. Data Types and sizeof()\n");
        printf("5. Constants and Arithmetic\n");
        printf("6. Temperature Conversion\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: program1(); 
            break;
            case 2: program2(); 
            break;
            case 3: program3(); 
            break;
            case 4: program4(); 
            break;
            case 5: program5(); 
            break;
            case 6: program6(); 
            break;
            case 0: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 0);
    return 0;
}