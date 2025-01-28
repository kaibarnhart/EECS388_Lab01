#include <stdio.h>
#include <string.h>

// Function to convert a single hexadecimal digit to binary
void hex_to_binary(char hex, char *binary) {
    switch (hex) {
        case '0': strcpy(binary, "0000"); break;
        case '1': strcpy(binary, "0001"); break;
        case '2': strcpy(binary, "0010"); break;
        case '3': strcpy(binary, "0011"); break;
        case '4': strcpy(binary, "0100"); break;
        case '5': strcpy(binary, "0101"); break;
        case '6': strcpy(binary, "0110"); break;
        case '7': strcpy(binary, "0111"); break;
        case '8': strcpy(binary, "1000"); break;
        case '9': strcpy(binary, "1001"); break;
        case 'A': strcpy(binary, "1010"); break;
        case 'B': strcpy(binary, "1011"); break;
        case 'C': strcpy(binary, "1100"); break;
        case 'D': strcpy(binary, "1101"); break;
        case 'E': strcpy(binary, "1110"); break;
        case 'F': strcpy(binary, "1111"); break;
    }
}

int main() {
    char hex_number[100];
    char binary[5];

    // Prompts user for input
    printf("Please enter a hex number:\n");
    scanf("%s", hex_number);

    // Process each character of the hexadecimal number
    printf("Binary equivalent:\n");
    for (int i = 0; i < strlen(hex_number); i++) {
        hex_to_binary(hex_number[i], binary);
        printf("%s", binary);
    }
    printf("\n");

    return 0;
}
