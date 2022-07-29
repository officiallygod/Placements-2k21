#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int mod = 1e9 + 7;

int maxcoins(vector<int> &A, int i, int j, vector<vector<int>> &dp)
{

    // base case
    if (j - i == 1)
        return 0;

    // check
    if (dp[i][j] != -1)
        return dp[i][j];

    int mx = INT_MIN;

    // we will jump to odd index only
    for (int k = i + 1; k < j; k += 2)
    {
        int left = maxcoins(A, i, k, dp);
        int right = maxcoins(A, k + 1, j, dp);
        int current = (A[i] * A[k] * A[k + 1] * A[j]) % mod;

        int result = ((left + right) % mod + current) % mod;
        mx = max(mx, result);
    }

    return dp[i][j] = mx;
}

int getmax(vector<int> &nums)
{
    // insert 1 at beginning and end
    nums.insert(begin(nums), 1);
    nums.push_back(1);
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return maxcoins(nums, 0, n - 1, dp);
}

int main()
{
    vector<int> lst = {3, 1, 5, 8};
    std::cout << getmax(lst);

    return 0;
}