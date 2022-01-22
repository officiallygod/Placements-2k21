#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;
    while (t--)
    {
        int ar1Sz, ar2Sz;
        cin >> ar1Sz >> ar2Sz;
        vector<int> ar1;
        vector<int> ar2;

        int k = 0, m = 0;
        cin >> k >> m;

        int PA, PB, MA, MB;
        cin >> PA >> PB >> MA >> MB;

        for (int i = 0; i < ar1Sz; i++)
        {
            ar1.push_back((PA * i) % MA);
        }
        for (int i = 0; i < ar2Sz; i++)
        {
            ar2.push_back((PB * i) % MB);
        }

        sort(ar1.begin(), ar1.end());
        sort(ar2.begin(), ar2.end());

        int arr1_End = ar1[k - 1];
        int arr2_Start = ar2[ar2Sz - m];
        if (arr1_End < arr2_Start)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
