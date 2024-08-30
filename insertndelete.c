#include <stdio.h>

/* Program to insert or delete an element at a certain user-defined position. */
void sarr(int arr1[], int n) {
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);
    }
}

void parr(int arr1[], int n) {
    printf("The elements of the array are: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}

void newin(int arr1[], int n) {
    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}

void newdel(int arr1[], int n) {
    printf("Array after delete: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
}

int insert(int arr1[], int n, int index, int value) {
    for (int i = n; i > index; i--) {
        arr1[i] = arr1[i - 1];
    }
    arr1[index] = value;
    return n + 1;
}

int delete(int arr1[], int n, int value) {
    int i, j;
    for (i = 0; i < n; i++) {
        if (arr1[i] == value) {
            for (j = i; j < n - 1; j++) {
                arr1[j] = arr1[j + 1];
            }
            n--;
            i--;
        }
    }
    return n;
}

int main() {
    int arr1[100], n, i, v;
    printf("Enter no. of elements: ");
    scanf("%d", &n);
    sarr(arr1, n);
    parr(arr1, n);

    int x;
    printf("To insert an element type '0', To delete an element type '1', To exit press '2':\n");
    scanf("%d", &x);

    while (x != 2) {
        if (x == 0) {
            printf("Enter the element you want to insert: ");
            scanf("%d", &v);
            printf("Enter the position you want to insert the element in: ");
            scanf("%d", &i);
            n = insert(arr1, n, i, v);
            newin(arr1, n);
        } else if (x == 1) {
            printf("Enter the element you want to delete: ");
            scanf("%d", &v);
            n = delete(arr1, n, v);
            newdel(arr1, n);
        }
        printf("To insert an element type '0', To delete an element type '1', To exit press '2':\n");
        scanf("%d", &x);
    }

    printf("\n");
    return 0;
}