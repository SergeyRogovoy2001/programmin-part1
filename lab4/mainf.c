#include <stdio.h>

int main(int argc, char const *argv[])
{
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;

    float expr_1 = (a * (b + c));
    float expr_2 = ((d * e * f) / (b - a + d * (c - f)));
    float expr_3 = (a * b - e);
    float expr_4 = (c + d * a - b);
    float result = expr_1 - expr_2 + expr_3 * expr_4;

    // Analyzing the expression
    // expr_1: no restrictions
    // expr_2: d != 0, c != f, b != a
    // expr_3: no restrictions
    // expr_4: no restrictions

//     (gdb) set var a=10
// (gdb) set var b=15
// (gdb) set var c=0
// (gdb) set var d=-3
// (gdb) set var e=2
// (gdb) set var f=4

    // a=10
    // b=15
    // c=0
    // d=-3
    // e=2
    // f=4
    // a * (b + c) = 10*15=150.0
    // (d * e * f) / (b - a + d * (c - f)) = (-24)/(17) = -1,41176474
    // (a * b - e) = 148,0
    // (c + d * a - b) = -45
    // expr_1 - expr_2 + expr_3 * expr_4 = 150,0 - 1,411764 - 148,0 * 45 = - 6508,58823526 / -6508.58838
    return 0;
}
