// Longest Common Prefix in an Array

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string getCommonPrefix(string a, string b)
    {
        string ans;
        int i = 0, j = 0;
        int m = a.length(), n = b.length();

        while (i < m && j < n)
        {
            if (a[i] != b[j])
                break;

            ans += a[i];
            i++;
            j++;
        }

        return ans;
    }

    string longestCommonPrefix(string arr[], int n)
    {
        string res = arr[0];

        for (int i = 1; i < n; i++)
        {
            res = getCommonPrefix(res, arr[i]);
        }

        if (res.compare("") == 0)
            return "-1";

        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        Solution ob;
        cout << ob.longestCommonPrefix(arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends