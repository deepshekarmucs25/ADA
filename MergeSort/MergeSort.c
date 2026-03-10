#include <stdio.h>

// Function to merge two sorted halves
void merge(int arr[], int low, int mid, int high)
{
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[50], R[50];   // Temporary arrays

    // Copy data into left array
    for(i = 0; i < n1; i++)
        L[i] = arr[low + i];

    // Copy data into right array
    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;      // Starting index of L[]
    j = 0;      // Starting index of R[]
    k = low;    // Starting index of merged array

    // Merge the two arrays
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[]
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[]
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int mid = (low + high) / 2;

        // Sort first half
        mergeSort(arr, low, mid);

        // Sort second half
        mergeSort(arr, mid + 1, high);

        // Merge both halves
        merge(arr, low, mid, high);
    }
}

int main()
{
    int arr[50], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

   
