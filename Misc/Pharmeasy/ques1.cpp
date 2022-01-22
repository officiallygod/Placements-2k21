#include <bits/stdc++.h>
using namespace std;

#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define MOD 1000000007

#define trace1(x) cout << #x << ": " << x << endl;
#define trace2(x, y) cout << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cout << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define trace4(a, b, c, d) cout << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;

typedef long long ll;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    ll i, j, n, m;
    string s;
    while (cin >> s)
    {
        n = s.length();
        vector<ll> cnt[26];
        ll is[n] = {0};
        for (i = 0; i < n; i++)
            cnt[s[i] - 'a'].pb(i);
        ll ls[26] = {0};
        for (i = 0; i < 26; i++)
        {
            if (cnt[i].size())
                ls[i] = cnt[i][cnt[i].size() - 1];
            else
                ls[i] = -1;
        }
        ll mp1[26], mp2[26];
        ll num = 0;
        for (i = 0; i < 26; i++)
        {
            if (cnt[i].size())
                mp1[i] = num, mp2[num] = i;
            if (cnt[i].size())
                num++;
        }
        ll vis[num] = {0};
        ll maxi = -1;
        for (i = 0; i < num; i++)
        {
            for (j = 0; j < num; j++)
            {
                if (vis[j])
                    continue;
                ll kk = mp2[j];
                ll fst = upper_bound(cnt[kk].begin(), cnt[kk].end(), maxi) - cnt[kk].begin();
                if (fst < cnt[kk].size())
                    fst = cnt[kk][fst];
                else
                    continue;
                ll pos = 1;
                for (ll k = j + 1; k < num; k++)
                {
                    if (vis[k] == 0 && ls[mp2[k]] < fst)
                        pos = 0;
                }
                if (pos == 1)
                {
                    char c = 'a' + mp2[j];
                    maxi = fst;
                    cout << c;
                    vis[j] = 1;
                    break;
                }
            }
        }
        cout << endl;
    }
    return 0;
}