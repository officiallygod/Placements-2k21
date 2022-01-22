// Implement Atoi

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        int ans = 0;
        int isNeg = 0;

        if (str[0] == '-')
            isNeg = 1;

        for (int i = isNeg; i < str.length(); i++)
        {
            int x = str[i] - '0';

            if (x > 9)
                return -1;
            else
            {
                ans = ans * 10 + x;
            }
        }

        if (isNeg)
            return ans * -1;

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
} // } Driver Code Ends