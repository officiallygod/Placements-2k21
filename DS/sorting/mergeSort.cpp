#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

void merge(int *arr, int l, int m, int n)
{
    // int k = 0;
    // int i = l;
    // int c[n - l];
    // int j = m + 1;

    // while (i <= m and j < n)
    // {
    //     if (arr[i] >= arr[j])
    //     {
    //         c[k] = arr[j];
    //         k++;
    //         j++;
    //     }
    //     else
    //     {
    //         c[k] = arr[i];
    //         k++;
    //         i++;
    //     }
    // }

    // while (i <= m)
    // {
    //     c[k] = arr[i];
    //     k++;
    //     i++;
    // }

    // while (j < n)
    // {
    //     c[k] = arr[j];
    //     k++;
    //     j++;
    // }

    // for (int m = 0; m < k; m++)
    // {
    //     arr[l + m] = c[m];
    // }
    // cout << endl;

    int n1 = m - l + 1;
    int n2 = n - m;

    int a[n1];
    int b[n2];

    for (int i = 0; i < n1; i++)
        a[i] = arr[l + i];

    for (int i = 0; i < n2; i++)
        b[i] = arr[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
}

void mergeSort(int *arr, int l, int n)
{
    if (l >= n)
        return;

    int m = (l + n) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, n);
    merge(arr, l, m, n);
}

int main()
{
    IOS;

    int arr[] = {2, 5, 1, 3, 7, 9, 6, -4};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";

    return 0;
}