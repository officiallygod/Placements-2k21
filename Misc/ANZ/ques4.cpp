#include <bits/stdc++.h>
using namespace std;

int pair_calc(int A[], int n, int K)
{
    int remf[K] = {0};
    for (int i = 0; i < n; i++)
        remf[A[i] % K] = remf[A[i] % K] + 1;

    int sum = remf[0] * (remf[0] - 1) / 2;
    for (int i = 1; i <= K / 2 && i != (K - i); i++)
        sum += remf[i] * remf[K - i];

    if (K % 2 == 0)
        sum += (remf[K / 2] * (remf[K / 2] - 1) / 2);

    return sum;
}

int pair_calc1(int A[], int n)
{
    int remf[100] = {0};
    for (int i = 0; i < n; i++)
        remf[A[i] % 100] = remf[A[i] % 100] + 1;

    int sum = remf[0] * (remf[0] - 1) / 2;
    for (int i = 1; i <= 100 / 2 && i != (100 - i); i++)
        sum += remf[i] * remf[100 - i];

    sum += (remf[100 / 2] * (remf[100 / 2] - 1) / 2);

    return sum;
}

int main()
{

    int arr[] = {10, 40, 90, 60};
    int arr1[] = {50, 60, 150, 50, 40};
    int n = 5;
    int K = 100;

    cout << pair_calc1(arr1, n);

    return 0;
}