// Sort an array of 0s, 1s and 2s

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    void sort012(int a[], int n)
    {
        int i = 0, j = 0, z = n - 1;

        while (j <= z) // j should be less than equal to z
        {
            if (a[j] == 0)
            {
                swap(a[i], a[j]);
                i++;
                j++;
            }

            else if (a[j] == 1) // Use Else If
            {
                j++;
            }

            else if (a[j] == 2) // Use Else If
            {
                swap(a[z], a[j]);
                z--;
            }

            // cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<" "<<a[3]<<" "<<a[4]<<" "<<endl;
        }
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends