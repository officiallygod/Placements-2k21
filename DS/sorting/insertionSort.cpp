#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

void insertionSort(int *arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (arr[j] > key && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    IOS;

    int arr[] = {2, 7, 3, 5, 9, 10, -4};
    int size = sizeof(arr) / sizeof(arr[0]);

    insertionSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";

    return 0;
}