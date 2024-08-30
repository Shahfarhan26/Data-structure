#include <stdio.h>

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void unionArrays(int arr1[], int size1, int arr2[], int size2) {
    int temp[size1 + size2];
    int i, j, k;

    // Copy elements of arr1 to temp
    for (i = 0; i < size1; i++) {
        temp[i] = arr1[i];
    }

    // Copy elements of arr2 to temp
    for (j = 0; j < size2; j++) {
        temp[i + j] = arr2[j];
    }

    int n = size1 + size2;

    // Sort the temp array
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (temp[i] > temp[j]) {
                int tempVar = temp[i];
                temp[i] = temp[j];
                temp[j] = tempVar;
            }
        }
    }

    // Remove duplicates and print result
    printf("Union of arrays: ");
    for (i = 0; i < n; i++) {
        if (i == 0 || temp[i] != temp[i - 1]) {
            printf("%d ", temp[i]);
        }
    }
    printf("\n");
}

int main() {
    int arr1[] = {1, 2, 4, 5, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    int arr2[] = {2, 3, 5, 7};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    unionArrays(arr1, size1, arr2, size2);

    return 0;
}

