#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int> &a)
{
    int maxValue = a[0], minValue = a[0];
    int res = maxValue;

    for (int i = 1; i < a.size(); i++)
    {
        int temp = maxValue;
        maxValue = max(temp * a[i], max(minValue * a[i], a[i]));
        minValue = min(minValue * a[i], min(temp * a[i], a[i]));

        res = max(res, maxValue);
    }
    return res;
}

int maxProductSubset(vector<int> a)
{
    int n = a.size();
    if (n == 1)
        return a[0];

    int max_neg = INT_MIN;
    int count_neg = 0, count_zero = 0;
    int prod = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            count_zero++;
            continue;
        }
        if (a[i] < 0)
        {
            count_neg++;
            max_neg = max(max_neg, a[i]);
        }

        prod = prod * a[i];
    }

    if (count_zero == n)
        return 0;
    if (count_neg & 1)
    {
        if (count_neg == 1 &&
            count_zero > 0 &&
            count_zero + count_neg == n)
            return 0;
        prod = prod / max_neg;
    }

    return prod;
}

int solve(vector<int> arr, vector<int> arr1)
{
    return maxProduct(arr) + maxProductSubset(arr1);
}

int main()
{
    vector<int> arr = {1, -2, -3, 4, -5, 6};
    vector<int> arr1 = {1, -2, -3, 4, -5, 6};

    vector<int> arr2 = {100, 0, 0, 1, 5, -2, -500, 0, 1, 1};
    vector<int> arr3 = {100, 0, 0, 1, 5, -2, -500, 0, 1, 1};

    cout << solve(arr, arr1) << endl;
    cout << solve(arr2, arr3) << endl;
}