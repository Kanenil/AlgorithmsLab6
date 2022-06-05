#include <iostream>
#include <time.h>
using namespace std;

const unsigned int NUM = 50000;

int A[NUM];           
int B[NUM];            


void CreateArray(int* arr, int* arr2) {
    srand(1);
    for (int i = 0; i < NUM; i++)
        arr[i] = arr2[i] = (int)rand();
}

void RestoreArray() 
{
    for (int i = 0; i < NUM; i++)
        A[i] = B[i];
}

int findpivot(int* arr, int i, int j) {
    int firstkey;

    firstkey = arr[i];
    for (int k = i + 1; k <= j; k++)
    {
        if (arr[k] > firstkey)
            return k;
        else if (arr[k] < firstkey)
            return i;
    }
    return -1;
}

int partition(int* arr, int i, int j, int pivot) {
    int l, r;

    l = i;
    r = j;
    do
    {
        swap(arr[l], arr[r]);
        while (arr[l] < pivot)
            l++;
        while (arr[r] >= pivot)
            r--;
    } while (l <= r);
    return l;
}

void quicksort(int* arr, int i, int j) {
    int pivot;
    int pivotindex;
    int k;

    pivotindex = findpivot(arr, i, j);
    if (pivotindex != -1)
    {
        pivot = arr[pivotindex];
        k = partition(arr, i, j, pivot);
        quicksort(arr, i, k - 1);
        quicksort(arr, k, j);
    }
}

int main() {
    CreateArray(A, B);

    int qsort = 0;
    int choisesort = 0;

    clock_t  begt, endt;
    for (int i = 1; i <= 5; i++)
    {
        printf("Round %d\n", i);
        begt = clock();
        int lowindex, lowkey;
        for (int i = 0; i < (NUM - 1); i++) {
            lowindex = i;
            lowkey = A[i];
            for (int j = i + 1; j < NUM; j++)
                if (A[j] < lowkey) {
                    lowkey = A[j];
                    lowindex = j;
                }
            swap(A[i], A[lowindex]);
        }

        endt = clock();
        printf("Choise sort time = %d\n", endt - begt);
        choisesort += endt - begt;

        RestoreArray();

        begt = clock();
        quicksort(A, 0, NUM - 1);
        endt = clock();
        printf("Quick Sort time = %d\n", endt - begt);
        qsort += endt - begt;
    }

    printf("Results:\nQuick Sort time = %d\nChoise Sort time = %d", qsort / 5, choisesort / 5);

    
}