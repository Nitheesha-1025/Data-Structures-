#include <cstdio>
#include"sort.h"
#include"search.h"



// Linear Search
void linearsearch(int arr[], int n, int data) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == data) { 
            printf("Found at index %d\n", i);
            return; 
        }
    }
    printf("Not found\n");
}

// Binary Search
void binarysearch(int arr[], int n, int data) {
    int l = 0, r = n - 1, m;
    bubblesort(arr, n); 
    while (l <= r) {
        m = (l + r) / 2;
        if (arr[m] == data) {
            printf("Found at index %d\n", m);
            return; 
        }
        else if (data < arr[m]) {
            r = m - 1;
        }
        else {
            l = m + 1;
        }
    }
    printf("Not found\n"); 
}

int main() {
    int i, n, opt, data;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int arr[n];
    printf("Enter the elements in the array: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    while (1) {
        printf("\nChoose a search method:\n");
        printf("1. Linear Search\n2. Binary Search\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &opt);

        switch (opt) {
            case 1:
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                linearsearch(arr, n, data);
                break;
            case 2:
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                binarysearch(arr, n, data);
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }
    return 0;
}
