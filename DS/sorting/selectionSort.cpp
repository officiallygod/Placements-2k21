#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

void selectionSort(int *arr, int n)
{
    int min_ind;
    for (int i = 0; i < n; i++)
    {
        min_ind = i;
        for (int j = i; j < n; j++)
            if (arr[j] < arr[min_ind])
                min_ind = j;
        swap(arr[i], arr[min_ind]);
    }
}

int main()
{
    IOS;

    int arr[] = {2, 7, 3, 5, 9, 10, -4};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";

    return 0;
}