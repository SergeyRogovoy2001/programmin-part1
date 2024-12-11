#include <stdio.h>
#include <stdlib.h>

// #define MY_GLOBAL_VARIABLE 120


int main(void)
{
    // int c = MY_GLOBAL_VARIABLE;
    // puts("Hello");

    int val_two = 0;
    int val_one = 0;
    int result = 0;

    result = val_one + val_two;

    printf("\n%d + %d = %d\n\n", val_one, val_two, result);
    char hellow[] = "hellow";
    printf("%s\n", hellow);

    return EXIT_SUCCESS;
}