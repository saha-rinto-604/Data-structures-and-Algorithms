#include <stdio.h>
#include <string.h>

int main() {
    int n;
    // Read the number of strings to input
    scanf("%d", &n);

    // Clear the input buffer (to remove newline after number input)
    while ((getchar()) != '\n');

    // Declare a 2D array to hold 'n' strings, each with max length 49 + 1 for '\0'
    char arr[n][50];

    // Take 'n' strings as input using fgets()
    for (int i = 0; i < n; i++) {
        printf("Enter the string %d: ", i + 1);
        fgets(arr[i], sizeof(arr[i]), stdin);
    }

    // Declare a string to hold the key we want to search for
    char x[1][50];

    // Take the key string as input
    printf("Enter the key: ");
    fgets(x[0], sizeof(x[0]), stdin);

    // Initialize binary search bounds
    int l = 0;
    int h = n - 1;
    int mid;

    // Binary search loop
    while (l <= h) {
        mid = (l + h) / 2;

        // If match is found
        if (strcmp(arr[mid], x[0]) == 0) {
            return mid; // Return the index (technically this exits the program)
        }

        // If arr[mid] is less than key, search right half
        else if (strcmp(arr[mid], x[0]) < 0) {
            l = mid + 1;
        }

        // Else search left half
        else {
            h = mid - 1;
        }
    }

    // If not found, return 0 (could indicate not found, but may be confusing as 0 is a valid index)
    return 0;
}
