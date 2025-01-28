#include <stdio.h>
#include <stdbool.h>

// this function makes sure the number is prime
bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int limit;

    // prompts user for input
    printf("Enter a number:\n");
    scanf("%d", &limit);

    //  if validate input
    if (limit < 2) {
        printf("No prime numbers.\n");
        return 0;
    }

    // Prints prime numbers up to limit
    for (int i = 2; i <= limit; i++) {
        if (is_prime(i)) {
            printf("%d ", i);
        }
    }

    printf("\n");
    return 0;
}
