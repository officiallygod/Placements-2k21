#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, val, ans = 0;
    vector<int> vc;
    cin >> n;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        vc.push_back(val);
        mp[val]++;
    }

    for (auto num : mp)
    {
        if (num.second == 1)
        {
            ans = num.first;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
