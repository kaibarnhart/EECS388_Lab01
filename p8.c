#include <stdio.h>

int main() {
    int num, bit;

    // Prompt for the integer
    printf("Enter integer:\n");
    scanf("%d", &num);

    // Prompt user for the bit position
    printf("Enter bit:\n");
    scanf("%d", &bit);

    // Check if the bit is set
    if (num & (1 << bit)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    return 0;
}
