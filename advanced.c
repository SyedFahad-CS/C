/* advanced_calc.c
   Advanced calculator using functions
   Compile: gcc advanced_calc.c -o advanced_calc -lm
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#define MAX_INPUT 128
/* --- Utility and validation --- */
void clear_stdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

double get_double(const char *prompt) {
    char buf[MAX_INPUT];
    double val;
    while (1) {
        printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) { printf("Input error\n"); exit(1); }
        if (sscanf(buf, "%lf", &val) == 1) return val;
        printf("Invalid number. Try again.\n");
    }
}

long long get_longlong(const char *prompt) {
    char buf[MAX_INPUT];
    long long val;
    while (1) {
        printf("%s", prompt);
        if (!fgets(buf, sizeof(buf), stdin)) { printf("Input error\n"); exit(1); }
        if (sscanf(buf, "%lld", &val) == 1) return val;
        printf("Invalid integer. Try again.\n");
    }
}

/* --- Basic operations --- */
double add(double a, double b) { return a + b; }
double sub(double a, double b) { return a - b; }
double mul(double a, double b) { return a * b; }
double division(double a, double b) {
    if (b == 0.0) { fprintf(stderr, "Error: division by zero.\n"); return NAN; }
    return a / b;
}

/* --- Power and roots --- */
double power_op(double base, double exp) { return pow(base, exp); }
double nth_root(double x, double n) {
    if (n == 0.0) { fprintf(stderr, "Error: zeroth root undefined.\n"); return NAN; }
    if (x < 0 && fmod(n, 2.0) != 1.0) {
        fprintf(stderr, "Error: even root of negative number (complex result) not supported.\n");
        return NAN;
    }
    return pow(x, 1.0 / n);
}

/* --- Factorial, permutations, combinations --- */
unsigned long long factorial_u64(unsigned int n) {
    if (n > 20) { /* 21! overflows 64-bit */
        fprintf(stderr, "Warning: factorial result will overflow unsigned long long for n > 20; returning 0.\n");
        return 0ULL;
    }
    unsigned long long res = 1ULL;
    for (unsigned int i = 2; i <= n; ++i) res *= i;
    return res;
}

double nPr(unsigned int n, unsigned int r) {
    if (r > n) return 0.0;
    unsigned long long res = 1ULL;
    for (unsigned int i = 0; i < r; ++i) res *= (n - i);
    return (double)res;
}

double nCr(unsigned int n, unsigned int r) {
    if (r > n) return 0.0;
    if (r > n - r) r = n - r;
    double res = 1.0;
    for (unsigned int i = 1; i <= r; ++i) res = res * (n - r + i) / i;
    return res;
}

/* --- Trigonometry (option to use degrees or radians) --- */
int use_degrees = 0;

double to_radians(double deg) { return deg * M_PI / 180.0; }
double trig_sin(double x) { return use_degrees ? sin(to_radians(x)) : sin(x); }
double trig_cos(double x) { return use_degrees ? cos(to_radians(x)) : cos(x); }
double trig_tan(double x) { return use_degrees ? tan(to_radians(x)) : tan(x); }

/* --- Log, exp --- */
double log_e(double x) {
    if (x <= 0.0) { fprintf(stderr, "Error: log undefined for x <= 0\n"); return NAN; }
    return log(x);
}
double log10_safe(double x) {
    if (x <= 0.0) { fprintf(stderr, "Error: log10 undefined for x <= 0\n"); return NAN; }
    return log10(x);
}
double exp_op(double x) { return exp(x); }

/* --- Base conversions --- */
void dec_to_base(long long value, int base, char *out, size_t out_size) {
    if (base < 2 || base > 36) { snprintf(out, out_size, "base error"); return; }
    if (value == 0) { snprintf(out, out_size, "0"); return; }
    int neg = (value < 0);
    unsigned long long v = (unsigned long long)(neg ? -value : value);
    char buf[128]; int p = 0;
    while (v > 0 && p < (int)sizeof(buf)-1) {
        int digit = v % base;
        buf[p++] = (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
        v /= base;
    }
    if (neg) buf[p++] = '-';
    buf[p] = '\0';
    /* reverse */
    int j = 0;
    for (int i = p - 1; i >= 0 && j < (int)out_size - 1; --i) out[j++] = buf[i];
    out[j] = '\0';
}

/* --- Menu and main loop --- */
void print_menu() {
    printf("\n--- Advanced Calculator ---\n");
    printf("Modes: %s\n", use_degrees ? "Degrees" : "Radians");
    printf("1) Add (a + b)\n");
    printf("2) Subtract (a - b)\n");
    printf("3) Multiply (a * b)\n");
    printf("4) Divide (a / b)\n");
    printf("5) Power (a ^ b)\n");
    printf("6) Nth root (nth_root(x, n))\n");
    printf("7) Factorial (n!)\n");
    printf("8) Permutation (nPr)\n");
    printf("9) Combination (nCr)\n");
    printf("10) sin(x)\n");
    printf("11) cos(x)\n");
    printf("12) tan(x)\n");
    printf("13) log (natural)\n");
    printf("14) log10\n");
    printf("15) exp(x)\n");
    printf("16) Decimal -> Binary/Oct/Hex/Any base\n");
    printf("17) Toggle Degrees/Radians\n");
    printf("18) Memory store (M=last result)\n");
    printf("19) Memory recall (MR)\n");
    printf("0) Exit\n");
}

int main(void) {
    double last_result = 0.0;
    double memory = 0.0;
    int choice;
    char buf[MAX_INPUT];

    while (1) {
        print_menu();
        printf("Choose option: ");
        if (!fgets(buf, sizeof(buf), stdin)) break;
        if (sscanf(buf, "%d", &choice) != 1) { printf("Invalid choice\n"); continue; }

        switch (choice) {
            case 0: printf("Goodbye!\n"); return 0;
            case 1: {
                double a = get_double("a = ");
                double b = get_double("b = ");
                last_result = add(a,b);
                printf("Result: %.12g\n", last_result);
                break;
            }
            case 2: {
                double a = get_double("a = ");
                double b = get_double("b = ");
                last_result = sub(a,b);
                printf("Result: %.12g\n", last_result);
                break;
            }
            case 3: {
                double a = get_double("a = ");
                double b = get_double("b = ");
                last_result = mul(a,b);
                printf("Result: %.12g\n", last_result);
                break;
            }
            case 4: {
                double a = get_double("a = ");
                double b = get_double("b = ");
                last_result = division(a,b);
                if (!isnan(last_result)) printf("Result: %.12g\n", last_result);
                break;
            }
            case 5: {
                double a = get_double("base = ");
                double b = get_double("exponent = ");
                last_result = power_op(a,b);
                printf("Result: %.12g\n", last_result);
                break;
            }
            case 6: {
                double x = get_double("x = ");
                double n = get_double("n (root degree) = ");
                last_result = nth_root(x,n);
                if (!isnan(last_result)) printf("Result: %.12g\n", last_result);
                break;
            }
            case 7: {
                long long n = get_longlong("n (non-negative integer) = ");
                if (n < 0) { printf("Error: negative factorial not supported.\n"); break; }
                unsigned long long f = factorial_u64((unsigned int)n);
                printf("%lld! = %llu\n", n, f);
                last_result = (double)f;
                break;
            }
            case 8: {
                long long n = get_longlong("n = ");
                long long r = get_longlong("r = ");
                if (n < 0 || r < 0) { printf("Error: negative values not allowed.\n"); break; }
                double res = nPr((unsigned int)n, (unsigned int)r);
                printf("nPr = %.0f\n", res);
                last_result = res;
                break;
            }
            case 9: {
                long long n = get_longlong("n = ");
                long long r = get_longlong("r = ");
                if (n < 0 || r < 0) { printf("Error: negative values not allowed.\n"); break; }
                double res = nCr((unsigned int)n, (unsigned int)r);
                printf("nCr = %.0f\n", res);
                last_result = res;
                break;
            }
            case 10: {
                double x = get_double("x = ");
                last_result = trig_sin(x);
                printf("sin = %.12g\n", last_result);
                break;
            }
            case 11: {
                double x = get_double("x = ");
                last_result = trig_cos(x);
                printf("cos = %.12g\n", last_result);
                break;
            }
            case 12: {
                double x = get_double("x = ");
                last_result = trig_tan(x);
                printf("tan = %.12g\n", last_result);
                break;
            }
            case 13: {
                double x = get_double("x = ");
                last_result = log_e(x);
                if (!isnan(last_result)) printf("ln = %.12g\n", last_result);
                break;
            }
            case 14: {
                double x = get_double("x = ");
                last_result = log10_safe(x);
                if (!isnan(last_result)) printf("log10 = %.12g\n", last_result);
                break;
            }
            case 15: {
                double x = get_double("x = ");
                last_result = exp_op(x);
                printf("exp = %.12g\n", last_result);
                break;
            }
            case 16: {
                long long val = get_longlong("Enter decimal integer (can be negative): ");
                printf("Choose base (2..36): ");
                int base;
                if (!fgets(buf, sizeof(buf), stdin)) break;
                if (sscanf(buf, "%d", &base) != 1) { printf("Invalid base\n"); break; }
                char out[128];
                dec_to_base(val, base, out, sizeof(out));
                printf("Base %d representation: %s\n", base, out);
                last_result = (double)val;
                break;
            }
            case 17: {
                use_degrees = !use_degrees;
                printf("Now using %s mode for trig functions.\n", use_degrees ? "Degrees" : "Radians");
                break;
            }
            case 18: {
                memory = last_result;
                printf("Stored %.12g in memory.\n", memory);
                break;
            }
            case 19: {
                printf("Memory recall: %.12g\n", memory);
                last_result = memory;
                break;
            }
            default:
                printf("Unknown choice\n");
        }
    }

    return 0;
}
