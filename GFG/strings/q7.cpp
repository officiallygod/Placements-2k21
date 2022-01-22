// Anagram

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {

        if (a.length() != b.length())
            return false;

        bool isAnagram = true;

        unordered_map<char, int> um1;
        unordered_map<char, int> um2;

        for (int i = 0; i < a.length(); i++)
        {
            um1[a[i]]++;
            um2[b[i]]++;
        }

        for (auto num : um1)
        {
            if (num.second != um2[num.first])
                isAnagram = false;
        }

        return isAnagram;
    }
};

// { Driver Code Starts.

int main()
{

    int t;

    cin >> t;

    while (t--)
    {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
// } Driver Code Ends