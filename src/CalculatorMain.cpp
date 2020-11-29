#include <stdio.h>
#include "Calculator.h"

int main(int argc, char **argv) {
    Calculator calculator;
    printf("1 + 1 = %d\n", calculator.sum(1, 1));
    printf("4 - 2 = %d\n", calculator.minus(4, 2));
    printf("25 * 15 = %d\n", calculator.multiply(25, 15));
    printf("10 / 2 = %d\n", calculator.divide(10, 2));
}
