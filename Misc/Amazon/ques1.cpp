#include <bits/stdc++.h>
using namespace std;

int minRemove(vector<int> arr, int n)
{
    int LIS[n], len = 0;
    for (int i = 0; i < n; i++)
        LIS[i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] >= arr[j])
            {
                LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
        len = max(len, LIS[i]);
    }

    return n - len;
}

int solve(int arr[], int n, int k)
{
    vector<vector<int>> ans;
    unordered_map<int, int> mp;
    for (int i = 0; i < n - k; i++)
    {
        vector<int> res;
        if (mp[i] != 1)
        {
            for (int j = i; j < n; j += k)
            {
                mp[j] = 1;
                res.push_back(arr[j]);
            }
            ans.push_back(res);
        }
    }
    int c = 0;
    for (auto i : ans)
    {
        int r = minRemove(i, i.size());
        cout << r << endl;
        c += r;
    }
    return c;
}

int main()
{
    int arr[] = {5, 5, 6, 5, 5, 5, 5};
    int arr1[] = {14, 20, 10, 12, 10, 14, 13, 18, 19, 15, 19, 14, 12, 14, 18};
    int arr2[] = {14, 20, 10, 12, 10, 14, 13, 18, 19, 15, 19, 14, 12, 14, 18};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << solve(arr1, n, 8);
    return 0;
}
