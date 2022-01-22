#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

int quick(int *arr, int l, int n)
{
    int pivot = arr[n];

    int i = l - 1;
    for (int j = l; j < n; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[n]);

    return i + 1;
}

void quickSort(int *arr, int l, int n)
{
    if (l >= n)
        return;

    int p = quick(arr, l, n - 1);
    quickSort(arr, l, p - 1);
    quickSort(arr, p + 1, n);
}

int main()
{
    IOS;

    int arr[] = {2, 5, 1, 3, 7, 9, 6, -4};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";

    return 0;
}