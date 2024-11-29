#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;

    int expr_1 = (a * (b + c));
    int expr_2 = ((d * e * f) / (b - a + d * (c - f)));
    int expr_3 = (a * b - e);
    int expr_4 = (c + d * a - b);
    int result = expr_1 - expr_2 + expr_3 * expr_4;

    // Analyzing the expression
    // expr_1: no restrictions
    // expr_2: d != 0, c != f, b != a
    // expr_3: no restrictions
    // expr_4: no restrictions
    return 0;
}
