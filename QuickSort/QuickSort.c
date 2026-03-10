#include <stdio.h>

void quick_sort(int a[], int low, int high);
int partition(int a[], int low, int high);
void swap(int a[], int i, int j);

void quick_sort(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        quick_sort(a, low, j - 1);
        quick_sort(a, j + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int i = low;
    int j = high + 1;
    int pivot = a[low];

    while (1) {
        do {
            i++;
        } while (i <= high && a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i >= j)
            break;

        swap(a, i, j);
    }

    swap(a, low, j);
    return j;
}

void swap(int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

int main() {
    int a[10];

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }

    quick_sort(a, 0, 9);

    printf("Sorted array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
