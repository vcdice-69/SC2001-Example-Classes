#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int S = 10;
int SIZE = 1000;
int list[1000];
long long comparisonCount = 0; // Global variable to count comparisons

void sort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void generate(int size);

int main()
{
    srand(time(0));
    generate(SIZE);
    printf("The unsorted array is:\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    sort(list, 0, SIZE-1);

    printf("The sorted array is:\n");
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d ", list[i]);
    }
    printf("\n");

    // Output the total number of comparisons
    printf("Total number of key comparisons: %lld\n", comparisonCount);
    return 0;
}

void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int lsize = mid - left + 1;
    int rsize = right - mid;

    int l[lsize], r[rsize];
    for(i = 0; i < lsize; i++){
        l[i] = arr[left + i];
    }
    for(j = 0; j < rsize; j++){
        r[j] = arr[mid + 1 + j];
    }
    i = 0; 
    j = 0;
    k = left;
    while (i < lsize && j < rsize) {
        comparisonCount++; // Counting comparison between l[i] and r[j]
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        }
        else {
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[]
    while (i < lsize) {
        arr[k] = l[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[]
    while (j < rsize) {
        arr[k] = r[j];
        j++;
        k++;
    }
}

void sort(int arr[], int left, int right)
{
    if(left < right)
    {
        if((right - left + 1) < S)
        {
            // Insertion Sort
            for (int i = 1; i < (right - left + 1); ++i) 
            {
                int key = arr[left + i];
                int j = i - 1;

                // Counting comparisons in Insertion Sort
                while (j >= 0 && arr[left + j] > key) 
                {
                    comparisonCount++; // Counting comparison between arr[left + j] and key
                    arr[left + j + 1] = arr[left + j];
                    j = j - 1;
                }
                comparisonCount++; // Counting the comparison when while loop condition fails
                arr[left + j + 1] = key;
            }
        } else {
            int mid = (left + (right - 1)) / 2;
            sort(arr, left, mid);
            sort(arr, mid+1, right);

            merge(arr, left, mid, right);
        }
    }
}

void generate(int size)
{
    for(int i = 0; i < size; i++)
    {
        list[i] = rand() % size + 1;
    }
}
