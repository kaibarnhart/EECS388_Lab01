#include <stdio.h>

int main() {
    int operand1, operand2, result;
    char operation;

    // Prompt for the first operand
    printf("Enter 1st operand:\n");
    scanf("%d", &operand1);

    // Prompt for the operation
    printf("Enter operation (+, -, *, /, s):\n");
    scanf(" %c", &operation); // Note the space before %c to ignore newline characters

    // Check the operation type
    if (operation == 's') {
        // Perform squaring
        result = operand1 * operand1;
        printf("%d\n", result);
    } else {
        // Prompt for the second operand
        printf("Enter 2nd operand:\n");
        scanf("%d", &operand2);

        // Perform the operation
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
