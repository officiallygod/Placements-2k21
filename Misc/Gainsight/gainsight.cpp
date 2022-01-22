#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int countPairsWithDiffK(int arr[], int n, int k)
{
    int i = 0;
    int j = 0;
    vector<pair<int, int>> vp;
    while (j + k <= n)
    {
        pair<int, int> p;
        p = make_pair(j, j + k);
        vp.push_back(p);
        j++;
    }
    int ans = 0;
    for (auto i : vp)
    {
        ans += (arr[i.first]) * (arr[i.second]);
    }
    return ans;
}

int main()
{
    int arr[] = {7, 8, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    cout << countPairsWithDiffK(arr, n, k);
    return 0;
}
