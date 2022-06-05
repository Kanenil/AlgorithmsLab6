#include <iostream>
#include <vector>

using namespace std;

vector<int> InsertSort(vector<int>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int j = i;
        while (arr[j] < arr[j - 1]) {
            swap(arr[j], arr[j - 1]);
            if (--j == 0)
                break;
        }
    }
    return arr;
}

//int main()
//{
//    vector<int> arr;
//    for (int i = 0; i < 10; i++)
//        arr.push_back(rand()%100);
//
//    for (int i = 0; i < arr.size(); i++)
//        cout << arr[i] << " ";
//    cout << endl;
//
//    InsertSort(arr);
//
//    for (int i = 0; i < arr.size(); i++)
//        cout << arr[i] << " ";
//    cout << endl;
//
//    return 0;
//}

