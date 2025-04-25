/*
 * ================================
 * Multipurpose Calculator in C
 * Created with the help of ChatGPT
 * Modified and customized by: Asma Akter
 * ================================
 * Features:
 * 1. Basic Arithmetic
 * 2. Trigonometric Functions
 * 3. Exponential and Logarithmic
 * 4. Factorial
 * 5. Power & Square Root
 * 6. Area Calculator
 * 7. Temperature Conversion
 * 8. Number Base Conversion
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Declarations
void basic_arithmetic();
void trigonometry();
void exponential_log();
void factorial();
void power_sqrt();
void area_calc();
void temperature_conv();
void base_conversion();

int main() {
    int choice;

    while(1) {
        printf("\n===== Welcome to Asma's Multipurpose Calculator =====\n");
        printf("1. Basic Arithmetic\n");
        printf("2. Trigonometric Functions\n");
        printf("3. Exponential and Logarithmic Functions\n");
        printf("4. Factorial\n");
        printf("5. Power and Square Root\n");
        printf("6. Area Calculation\n");
        printf("7. Temperature Conversion\n");
        printf("8. Number Base Conversion\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: basic_arithmetic(); break;
            case 2: trigonometry(); break;
            case 3: exponential_log(); break;
            case 4: factorial(); break;
            case 5: power_sqrt(); break;
            case 6: area_calc(); break;
            case 7: temperature_conv(); break;
            case 8: base_conversion(); break;
            case 0: 
                printf("Thank you for using Asma's Calculator!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// 1. Basic Arithmetic Calculator
void basic_arithmetic() {
    float a, b;
    char op;
    printf("\nEnter an expression (e.g., 8 + 2): ");
    scanf("%f %c %f", &a, &op, &b);

    switch(op) {
        case '+': printf("Result: %.2f\n", a + b); break;
        case '-': printf("Result: %.2f\n", a - b); break;
        case '*': printf("Result: %.2f\n", a * b); break;
        case '/': 
            if(b != 0) printf("Result: %.2f\n", a / b);
            else printf("Error: Cannot divide by zero.\n");
            break;
        default: printf("Invalid operator.\n");
    }
}

// 2. Trigonometric Functions
void trigonometry() {
    double angle;
    int choice;
    printf("\nEnter angle in degrees: ");
    scanf("%lf", &angle);
    angle = angle * M_PI / 180.0;

    printf("1. sin\n2. cos\n3. tan\nChoose function: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1: printf("sin(θ) = %.4f\n", sin(angle)); break;
        case 2: printf("cos(θ) = %.4f\n", cos(angle)); break;
        case 3: printf("tan(θ) = %.4f\n", tan(angle)); break;
        default: printf("Invalid choice.\n");
    }
}

// 3. Exponential and Logarithmic
void exponential_log() {
    double x;
    int option;
    printf("\n1. e^x\n2. ln(x)\n3. log10(x)\nChoose an option: ");
    scanf("%d", &option);
    printf("Enter value of x: ");
    scanf("%lf", &x);

    switch(option) {
        case 1: printf("e^%.2f = %.4f\n", x, exp(x)); break;
        case 2: 
            if(x > 0) printf("ln(%.2f) = %.4f\n", x, log(x));
            else printf("Error: ln(x) undefined for x <= 0\n");
            break;
        case 3:
            if(x > 0) printf("log10(%.2f) = %.4f\n", x, log10(x));
            else printf("Error: log10(x) undefined for x <= 0\n");
            break;
        default: printf("Invalid option.\n");
    }
}

// 4. Factorial
void factorial() {
    int n, i;
    unsigned long long fact = 1;
    printf("\nEnter a non-negative integer: ");
    scanf("%d", &n);

    if(n < 0) {
        printf("Error: Factorial is not defined for negative numbers.\n");
        return;
    }

    for(i = 1; i <= n; i++)
        fact *= i;

    printf("Factorial of %d is %llu\n", n, fact);
}

// 5. Power and Square Root
void power_sqrt() {
    double x, y;
    int choice;

    printf("\n1. Power (x^y)\n2. Square Root\nChoose: ");
    scanf("%d", &choice);

    if(choice == 1) {
        printf("Enter base and exponent: ");
        scanf("%lf %lf", &x, &y);
        printf("Result = %.4f\n", pow(x, y));
    } else if(choice == 2) {
        printf("Enter number: ");
        scanf("%lf", &x);
        if(x >= 0) printf("Square root = %.4f\n", sqrt(x));
        else printf("Error: Negative number.\n");
    } else {
        printf("Invalid choice.\n");
    }
}

// 6. Area Calculation
void area_calc() {
    int shape;
    double a, b;

    printf("\nChoose shape:\n1. Square\n2. Rectangle\n3. Circle\n4. Triangle\nEnter choice: ");
    scanf("%d", &shape);

    switch(shape) {
        case 1:
            printf("Enter side: ");
            scanf("%lf", &a);
            printf("Area = %.2f\n", a * a);
            break;
        case 2:
            printf("Enter length and width: ");
            scanf("%lf %lf", &a, &b);
            printf("Area = %.2f\n", a * b);
            break;
        case 3:
            printf("Enter radius: ");
            scanf("%lf", &a);
            printf("Area = %.2f\n", M_PI * a * a);
            break;
        case 4:
            printf("Enter base and height: ");
            scanf("%lf %lf", &a, &b);
            printf("Area = %.2f\n", 0.5 * a * b);
            break;
        default:
            printf("Invalid shape.\n");
    }
}

// 7. Temperature Conversion
void temperature_conv() {
    double temp;
    int option;

    printf("\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\nChoose: ");
    scanf("%d", &option);

    if(option == 1) {
        printf("Enter Celsius: ");
        scanf("%lf", &temp);
        printf("Fahrenheit = %.2f\n", (temp * 9/5) + 32);
    } else if(option == 2) {
        printf("Enter Fahrenheit: ");
        scanf("%lf", &temp);
        printf("Celsius = %.2f\n", (temp - 32) * 5/9);
    } else {
        printf("Invalid choice.\n");
    }
}

// 8. Number Base Conversion
void base_conversion() {
    int num;
    printf("\nEnter a decimal number: ");
    scanf("%d", &num);
    printf("Binary: ");
    for(int i = 31; i >= 0; i--)
        printf("%d", (num >> i) & 1);

    printf("\nOctal: %o", num);
    printf("\nHexadecimal: %X\n", num);
}
