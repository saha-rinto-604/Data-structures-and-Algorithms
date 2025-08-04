#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// Binary search to find element in B closest to target - a
int findClosestIndex(int B[], int sizeB, int target) {
    int low = 0, high = sizeB - 1, mid;
    int closestIndex = 0;
    int minDiff = INT_MAX;

    while (low <= high) {
        mid = (low + high) / 2;
        int diff = abs(B[mid] - target);

        if (diff < minDiff) {
            minDiff = diff;
            closestIndex = mid;
        }

        if (B[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return closestIndex;
}

void findClosestPair(int A[], int sizeA, int B[], int sizeB, int target) {
    int closestA = 0, closestB = 0;
    int minDiff = INT_MAX;

    for (int i = 0; i < sizeA; i++) {
        int needed = target - A[i];
        int idx = findClosestIndex(B, sizeB, needed);
        int sum = A[i] + B[idx];
        int diff = abs(sum - target);

        if (diff < minDiff) {
            minDiff = diff;
            closestA = A[i];
            closestB = B[idx];
        }
    }

    printf("Closest pair: (%d, %d) with sum %d and difference %d\n",
           closestA, closestB, closestA + closestB, minDiff);
}

int main() {
    int A[] = {1, 4, 5, 7};
    int B[] = {10, 20, 30, 40};
    int target = 32;

    int sizeA = sizeof(A) / sizeof(A[0]);
    int sizeB = sizeof(B) / sizeof(B[0]);

    findClosestPair(A, sizeA, B, sizeB, target);

    return 0;
}
