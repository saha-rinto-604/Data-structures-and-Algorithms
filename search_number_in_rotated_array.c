#include <stdio.h>

int main() {
    int num;

    //  Prompt user to enter the size of the array
    printf("Enter the array size: ");
    scanf("%d", &num);

    //  Declare array with user-defined size
    int arr[num];

    //  Prompt user to enter array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < num; i++) {
        scanf("%d", &arr[i]);  // ⬅ Reading each element
    }

    //  Initialize binary search pointers
    int l = 0;
    int h = num - 1;
    int mid;

    int key;
    // 🔹 Prompt user to enter the key to search for
    printf("Enter the key: ");
    scanf("%d", &key);

    // 🔍 Begin binary search in rotated sorted array
    while (l <= h) {
        mid = (l + h) / 2;

        //  If key is found at mid
        if (arr[mid] == key) {
            printf("Key %d found at index %d\n", key, mid);
            return 0;
        }

        // 🔍 Check if left half is sorted
        if (arr[l] <= arr[mid]) {
            // 🔹 Key lies within the left half
            if (key >= arr[l] && key <= arr[mid]) {
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        // 🔍 Otherwise, right half is sorted
        else {
            // 🔹 Key lies within the right half
            if (key >= arr[mid] && key <= arr[h]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
    }

    //  Key not found in array
    printf("Key %d not found in the array\n", key);
    return 0;
}



