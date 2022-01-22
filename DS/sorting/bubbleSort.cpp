#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

void bubbleSort(int *arr, int n)
{

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
}

int main()
{
    IOS;

    int arr[] = {2, 7, 3, 5, 9, 10, -5};
    int size = sizeof(arr) / sizeof(arr[0]);

    bubbleSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";

    return 0;
}