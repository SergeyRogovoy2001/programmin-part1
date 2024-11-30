#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    // Set 2:
    double a = 1;
    double b = M_PI / 6;
    double c_var = 2;
    double d = 3;

    // expr_1: −0.012724451117138685
    // expr_2: 1.5533095657752118
    // result: −0.008191832071019456

    double expr_1 = (exp(tan(a))) + log(sin(b) + cos(c_var));
    printf("expr_1: %f\n", expr_1);
    double expr_2 = pow(pow(a, 3) + pow(b, 3) + pow(c_var, 3), 1.0 / 5.0);
    printf("expr_2: %f\n", expr_2);
    double result = expr_1 / expr_2;
    printf("Result: %f\n", result);

    // double expr_1 = (exp(tan(a))) + log(sin(b) + cos(c_var));
    // double expr_2 = pow(pow(a, 3) + pow(b, 3) + pow(c_var, 3), 1.0/ 5.0);
    // double result = expr_1 / expr_2;
    // printf("Result: %f\n", result);
    return 0;
}