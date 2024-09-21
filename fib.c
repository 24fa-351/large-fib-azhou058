#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long long int fib_iterative(int n) {
    if (n <= 1) {
        return n;
    }

    long long int first_number = 0;
    long long int second_number = 1;
    long long int next_number;

    for (int i = 2; i <= n; i++) {
         if (LLONG_MAX - second_number < first_number) {
         printf("Overflow on index: %d\n", i);
         return second_number;
         break;
         
      }
        next_number = first_number + second_number;
        first_number = second_number;
        second_number = next_number;
    }
    return second_number;
}

long long int fib_recursive(int n) {
    if (n <= 1) {
        return n;
    } else {
         return (fib_recursive(n - 1) + fib_recursive(n - 2));
    }
}

int main(int argc, char *argv[]) {
    int input_num = atoi(argv[1]);

    FILE *file = fopen(argv[2], "r");

    int N = input_num;

    long long int result;

    if (argv[2][0] == 'i') {
        result = fib_iterative(N-1);
    } else if (argv[2][0] == 'r') {
        result = fib_recursive(N-1);
    } else {
        printf("Error: Second argument must be 'i' (iterative) or 'r' (recursive)\n");
        return 1;
    }

    printf("%lld\n", result);

    return 0;
}