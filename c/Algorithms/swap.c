#include <stdio.h>

int main () {
    int a = 5;
    int b = 7;
    printf("a is %i and b is %i", a, b);
    a = a + b - (b = a);
    printf("a is %i and b is %i", a, b);
    return 0;
}
