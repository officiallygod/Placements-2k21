#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

void countingSort(int *arr, int n)
{
    int mx = INT_MIN;
    for (int i = 0; i < n; i++)
        mx = max(mx, arr[i]);

    int temp[mx + 1];

    for (int i = 0; i <= mx; i++)
        temp[i] = 0;

    for (int i = 0; i < n; i++)
        temp[arr[i]]++;

    for (int i = 1; i <= mx; i++)
        temp[i] = temp[i] + temp[i - 1];

    int output[n];

    for (int i = n - 1; i >= 0; i--)
        output[--temp[arr[i]]] = arr[i];

    // for (int i = 0; i < n; i++)
    //     cout << output[i] << "  ";

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main()
{
    IOS;

    int arr[] = {2, 7, 3, 5, 9, 10, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";

    return 0;
}