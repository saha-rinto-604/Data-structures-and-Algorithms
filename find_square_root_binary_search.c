#include <stdio.h>

int main() {
    int n;

    // Prompt user for the number to find the square root of
    printf("Enter the number: ");
    scanf("%d", &n);

    int l = 0;          // Initialize lower bound of search space
    int h = n - 1;      // Initialize upper bound of search space

    // Perform binary search for up to 20 iterations
    for (int i = 0; i <= 20; i++) {
        int mid = (l + h) / 2; // Find middle value of current search space

        // If mid*mid equals n, then mid is the exact square root
        if (mid * mid == n) {
            return mid; // Found the square root
        }

        // If mid*mid is less than n, move to the right half
        else if (mid * mid < n) {
            l = mid + 1;
        }

        // If mid*mid is greater than n, move to the left half
        else {
            h = mid - 1;
        }
    }

    return 0;
}
