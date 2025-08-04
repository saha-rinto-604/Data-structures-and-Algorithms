#include <stdio.h>

int main()
{
    int n;

    // Prompt user to enter array size
    printf("Enter the array size: ");
    scanf("%d", &n);

    int a[n];

    // Prompt user to enter the array elements
    printf("Enter the array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Sort the array using Bubble Sort
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                // Swap adjacent elements if they are out of order
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Print the sorted array
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // Prompt user to enter the key to search for
    int key;
    printf("\nEnter the key: ");
    scanf("%d", &key);

    // Binary search for the first occurrence of the key
    int l = 0;
    int h = n - 1;
    int mid;
    int first_occur = -1;

    while (l <= h)
    {
        mid = (l + h) / 2;

        if (a[mid] == key)
        {
            first_occur = mid;  // Store index and search in left half
            h = mid - 1;
        }
        else if (a[mid] < key)
        {
            l = mid + 1;  // Move to right half
        }
        else
        {
            h = mid - 1;  // Move to left half
        }
    }

    // Binary search for the last occurrence of the key
    int l1 = 0;
    int h1 = n - 1;
    int mid1;
    int last_occur = -1;

    while (l1 <= h1)
    {
        mid1 = (l1 + h1) / 2;

        if (a[mid1] == key)
        {
            last_occur = mid1;  // Store index and search in right half
            l1 = mid1 + 1;
        }
        else if (a[mid1] < key)
        {
            l1 = mid1 + 1;  // Move to right half
        }
        else
        {
            h1 = mid1 - 1;  // Move to left half
        }
    }

    // Calculate frequency using first and last occurrence
    int frequency;
    frequency = (last_occur - first_occur) + 1;

    // If key not found, set frequency to 0
    if (first_occur == -1 || last_occur == -1)
    {
        frequency = 0;
    }

    // Print the frequency
    printf("The total frequency is: %d\n", frequency);

    return 0;
}
