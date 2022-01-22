// Subarray with given sum

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int sum)
    {
        // Sliding Window Problem

        vector<int> vec;
        int curr_sum = arr[0];
        int i = 0, start = 0;

        for (i = 1; i <= n; i++)
        {
            while (curr_sum > sum and start < n - 1)
            {
                curr_sum = curr_sum - arr[start];
                start++;
                // cout<<"Removing..."<<i<<" : "<<curr_sum<<endl;
            }

            if (curr_sum == sum)
            {
                vec.push_back(start + 1);
                vec.push_back(i);
                return vec;
            }

            if (i < n)
                curr_sum += arr[i];

            // cout<<i<<" : "<<curr_sum<<endl;
        }

        vec.push_back(-1);
        return vec;
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
        long long s;
        cin >> n >> s;
        int arr[n];

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
} // } Driver Code Ends