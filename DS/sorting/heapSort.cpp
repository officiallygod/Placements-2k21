#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

void maxHeapify(int *arr, int n, int i)
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;

    if (left < n and arr[left] > arr[largest])
        largest = left;

    if (right < n and arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void buildHeap(int *arr, int n)
{
    for (int i = (n - 2) / 2; i >= 0; i--)
        maxHeapify(arr, n, i);
}

void heapSort(int *arr, int l, int n)
{
    buildHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        maxHeapify(arr, i, 0);
    }
}

int main()
{
    IOS;

    int arr[] = {2, 5, 1, 3, 7, 9, 6, -4};
    int size = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, 0, size);

    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";

    return 0;
}