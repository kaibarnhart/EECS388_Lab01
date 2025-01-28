#include <stdio.h>

int main() {
    int weight;
    char classification;

    // ask user for vehicle weight
    printf("Enter the weight of the vehicle in lbs:\n");
    scanf("%d", &weight);

    // This classifies the vehicle based on weight
    if (weight < 10000) {
        classification = 'l'; // Light weight
    } else if (weight >= 10000 && weight < 26000) {
        classification = 'm'; // Medium weight
    } else {
        classification = 'h'; // Heavy duty
    }

    // Output1
    printf("%c\n", classification);

    return 0;
}
