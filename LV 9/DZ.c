#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)  
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                printArray(arr, n);
            }
}

int main()
{
    int arr[] = { 8, -2, 11, 3, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    printf("Sortirano polje: \n");
    printArray(arr, n);
    return 0;
}