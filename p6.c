#include <stdio.h>

int main() {
    char str[100];
    char *ptr;
    int length = 0;

    // Prompts  user for a string
    printf("Enter string:\n");
    scanf("%s", str);

    // Makes the pointer start at the beginning of the string
    ptr = str;

    // pointer traverses the string
    while (*ptr != '\0') {
        length++;
        ptr++;
    }

    // print length of the string
    printf("%d\n", length);

    return 0;
}
