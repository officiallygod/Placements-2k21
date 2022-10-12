#include <bits/stdc++.h>
using namespace std;

int pair_calc1(vector<int> A)
{
    int n = A.size();
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
    vector<int> arr = {10, 40, 90, 60};
    vector<int> arr1 = {50, 60, 150, 50, 40};

    cout << pair_calc1(arr1);

    return 0;
}