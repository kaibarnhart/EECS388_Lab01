#include <stdio.h>

int main() {
    int operand1, operand2, result;
    char operation;

    // Prompts the first operand
    printf("Enter 1st operand:\n");
    scanf("%d", &operand1);

    // Prompts for the operation
    printf("Enter operation:\n");
    scanf(" %c", &operation);

    // Check the operation type
    if (operation == 's') {
        // Squares
        result = operand1 * operand1;
        printf("%d\n", result);
    } else {
        // Prompt for second operand
        printf("Enter 2nd operand:\n");
        scanf("%d", &operand2);

        // Performs  operation
        switch (operation) {
            case '+':
                result = operand1 + operand2;
            printf("%d\n", result);
            break;
            case '-':
                result = operand1 - operand2;
            printf("%d\n", result);
            break;
            case '*':
                result = operand1 * operand2;
            printf("%d\n", result);
            break;
            case '/':
                if (operand2 != 0) {
                    result = operand1 / operand2;
                    printf("%d\n", result);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
            break;
            default:
                printf("Error: Invalid operation.\n");
        }
    }

    return 0;
}
