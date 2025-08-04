#include <stdio.h>

// Sort array using insertion sort
void sort(int a[], int n){
    int i, j, key;
    for(i = 1; i < n; i++){
        key = a[i];
        j = i - 1;
        while(j >= 0 && a[j] > key){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

// Find the first index of a target using binary search
int firstOccurrence(int arr[], int low, int high, int key){
    int result = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == key){
            result = mid;
            high = mid - 1;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return result;
}

// Find the last index of a target using binary search
int lastOccurrence(int arr[], int low, int high, int key){
    int result = -1;
    while(low <= high){
        int mid = (low + high) / 2;
        if(arr[mid] == key){
            result = mid;
            low = mid + 1;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return result;
}

// Create frequency table using binary search
int findFrequency(int a[], int f[][2], int n){
    int i = 0, k = 0;
    while(i < n){
        int first = firstOccurrence(a, i, n - 1, a[i]);
        int last = lastOccurrence(a, i, n - 1, a[i]);
        f[k][0] = a[i];
        f[k][1] = last - first + 1;
        k++;
        i = last + 1;
    }
    return k;
}

// Sort frequency table in descending order by frequency
void FrequencySort(int a[][2], int n){
    for(int i = 1; i < n; i++){
        int element = a[i][0];
        int key = a[i][1];
        int j = i - 1;
        while(j >= 0 && a[j][1] < key){
            a[j + 1][0] = a[j][0];
            a[j + 1][1] = a[j][1];
            j--;
        }
        a[j + 1][0] = element;
        a[j + 1][1] = key;
    }
}

int main(){
    int a[] = {5, 2, 4, 1, 2, 5, 2, 1, 8, 2, 4, 8};
    int n = 12;

    // Step 1: Sort the original array
    sort(a, n);

    // Step 2: Build frequency table using binary search
    int frequency[n][2];
    int unique_elements = findFrequency(a, frequency, n);

    // Step 3: Sort elements by descending frequency
    FrequencySort(frequency, unique_elements);

    // Step 4: Rebuild the array based on sorted frequency
    int k = 0;
    for(int i = 0; i < unique_elements; i++){
        for(int j = 0; j < frequency[i][1]; j++){
            a[k++] = frequency[i][0];
        }
    }

    // Step 5: Print the final sorted array
    for(int i = 0; i < n; i++)
        printf("%d\t", a[i]);

    return 0;
}
