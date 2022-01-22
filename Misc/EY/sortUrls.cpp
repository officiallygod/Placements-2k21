#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<string, int> &a,
               const pair<string, int> &b)
{
    return (a.second > b.second);
}

int main()
{
    string str = "";
    int n, mx = 0;
    vector<pair<string, int>> vc;
    unordered_map<string, int> mp;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;
        mp[str]++;
    }

    for (auto url : mp)
    {
        vc.push_back(make_pair(url.first, url.second));
        mx++;
    }
    cout << mx << endl;
    sort(vc.begin(), vc.end(), sortbysec);

    for (auto url : vc)
    {
        cout << url.first << endl;
    }
    return 0;
}
