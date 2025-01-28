#include <stdio.h>

int main() {
    int n;

    // Prompt user for size of the array
    printf("How big is the array?\n");
    scanf("%d", &n);

    int arr[n], duplicates[100] = {0};
    int count = 0;

    // User inputs elements of the array
    for (int i = 0; i < n; i++) {
        printf("Enter element %d:\n", i + 1);
        scanf("%d", &arr[i]);
    }

    // Finds duplicates
    for (int i = 0; i < n; i++) {
        if (duplicates[arr[i]] == 0) { // Makes it procces unique elements
            int freq = 0;
            for (int j = 0; j < n; j++) {
                if (arr[i] == arr[j]) {
                    freq++;
                }
            }
            if (freq > 1) {
                count++;
                duplicates[arr[i]] = 1; // Marks as processed
            }
        }
    }

    // Print 
    printf("%d\n", count);

    return 0;
}
