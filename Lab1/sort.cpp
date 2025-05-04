#include <cstdio>
#include <cstdlib>

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Bubble Sort
void bubblesort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printArray(a, n);
}

// Selection Sort
void selectionsort(int arr[], int n) {
    int i, j, minIdx, temp;
    for (i = 0; i < n - 1; i++) {
        minIdx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        
        if (minIdx != i) {
            temp = arr[i];
            arr[i] = arr[minIdx];
            arr[minIdx] = temp;
        }
    }
    printArray(arr, n);
}

// Insertion Sort
void insertionsort(int arr[], int n) {
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = temp;
    }
    printArray(arr, n);
}

int main() {
    int i, n, opt;

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

    while(1){
    printf("\nChoose a sorting algorithm:\n");
    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &opt);

    
    switch (opt) {
        case 1:
            bubblesort(arr, n);
            break;
        case 2:
            selectionsort(arr, n);
            break;
        case 3:
            insertionsort(arr, n);
            break;
        case 4:
            printf("Exiting program.\n");
            return 0;
        default:
            printf("Invalid choice.\n");
            break;
    }
    }

    return 0;
}
