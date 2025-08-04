#include<stdio.h>

int main()
{
    int n;

    // Input the array size
    printf("Enter the array size: ");
    scanf("%d", &n);

    int arr[n];

    // Input the array elements
    printf("Enter the array elements:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Sort the array using bubble sort
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                // Swap elements if out of order
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("The sorted array is: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Initialize variables to find the first occurrence of 1
    int l = 0;
    int h = n - 1;
    int mid;
    int f_o = -1;

    // Binary search for first occurrence of 1
    while (l <= h) {
        mid = (l + h) / 2;

        if (arr[mid] == 1) {
            f_o = mid;
            h = mid - 1; // Move left to find earlier occurrence
        } else if (arr[mid] < 1) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }

    // Initialize variables to find the last occurrence of 1
    int l1 = 0;
    int h1 = n - 1;
    int mid1;
    int l_o = -1;

    // Binary search for last occurrence of 1
    while (l1 <= h1) {
        mid1 = (l1 + h1) / 2;

        if (arr[mid1] == 1) {
            l_o = mid1;
            l1 = mid1 + 1; // Move right to find later occurrence
        } else if (arr[mid1] < 1) {
            l1 = mid1 + 1;
        } else {
            h1 = mid1 - 1;
        }
    }

    // Calculate the total number of 1's
    int t_occur;
    if (f_o != -1 && l_o != -1) {
        t_occur = (l_o - f_o) + 1;
    } else {
        t_occur = 0; // No 1's found
    }

    // Print the count of 1s
    printf("The count of 1's are: %d\n", t_occur);

    return 0;
}
