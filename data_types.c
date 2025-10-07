#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
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
    printf("short       : %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("int         : %d to %d\n", INT_MIN, INT_MAX);
    printf("long        : %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("long long   : %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("float       : %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double      : %e to %e\n", DBL_MIN, DBL_MAX);
    printf("long double : %Le to %Le\n", LDBL_MIN, LDBL_MAX);
    return 0;
}
