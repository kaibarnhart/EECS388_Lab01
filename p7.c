#include <stdio.h>

int main() {
    int temp;
    int *temp_ptr;

    // prompts user for input
    printf("Enter integer:\n");
    scanf("%d", &temp);

    // sets the pointer to adress of temp 
    temp_ptr = &temp;

    printf("%d\n", temp);              // The value of ‘temp’ using ‘temp’
    printf("%d\n", *temp_ptr);         // The value of ‘temp’ using the dereferenced ‘temp_ptr’
    printf("%p\n", (void *)&temp);     // The address of ‘temp’ using the reference of ‘temp’
    printf("%p\n", (void *)temp_ptr);  // The address of ‘temp’ using ‘temp_ptr’

    return 0;
}
