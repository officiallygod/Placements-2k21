#include <bits/stdc++.h>
using namespace std;

int find_Sol(int input1, int input2, int input3)
{
    vector<vector<int>> dp(input1, vector<int>(input3 - input2 + 1, 1));
    int ans = input3 - input2 + 1 + input1 - 1;
    for (int i = 1; i < dp[0].size(); i++)
    {
        dp[0][i] += dp[0][i - 1];
    }
    for (int i = 1; i < input1; i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            ans += dp[i - 1][j];
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return ans;
}

int main()
{
    int res = find_Sol(1, 4, 5);
    cout << res << endl;
    return 0;
}