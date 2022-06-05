#include <iostream>
#include <ctime>
using namespace std;

struct INF {
    int key;
    char info;
};

INF* RandomStruct(int n)
{
    INF* arr = new INF[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].info = (char)rand() % (26) + 'a';
        arr[i].key = rand() % 100;
    }
    return arr;
}

void Print(INF* arr, int size) {
    for (int i = 0; i < size; i++) 
        cout << arr[i].key << ";" << arr[i].info << " ";
    cout << endl;
}

int findpivot(INF* arr, int i, int j) {
    int firstkey;

    firstkey = arr[i].key;
    for (int k = i + 1; k <= j; k++) 
    {
        if (arr[k].key > firstkey)
            return k;
        else if (arr[k].key < firstkey)
            return i;
    }
    return -1;
}

int partition(INF* arr, int i, int j, int pivot) {
    int l, r;

    l = i;
    r = j;
    do 
    {
        swap(arr[l], arr[r]);
        while (arr[l].key < pivot)
            l++;
        while (arr[r].key >= pivot)
            r--;
    } while (l <= r);
    return l;
}

void quicksort(INF* arr, int i, int j) {
    int pivot;
    int pivotindex;
    int k;

    pivotindex = findpivot(arr, i, j);
    if (pivotindex != -1) 
    {
        pivot = arr[pivotindex].key;
        k = partition(arr, i, j, pivot);
        quicksort(arr, i, k - 1);
        quicksort(arr, k, j);
    }
}

//int main() {
//    srand(time(NULL));
//    INF* arr = RandomStruct(10);
//    Print(arr, 10);
//    quicksort(arr, 0, 9);
//    Print(arr, 10);
//}