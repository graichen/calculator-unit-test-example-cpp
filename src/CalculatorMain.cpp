#include <stdio.h>
#include "Calculator.h"

int main(int argc, char **argv) {
    Calculator calculator;
    printf("1 + 1 = %f\n", calculator.sum(1, 1));
    printf("4 - 2 = %f\n", calculator.minus(4, 2));
    printf("2.5 * 1.5 = %f\n", calculator.multiply(2.5, 1.5));
    printf("10 / 2 = %f\n", calculator.divide(10, 2));
}
