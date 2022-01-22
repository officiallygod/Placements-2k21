#include <bits/stdc++.h>
using namespace std;
typedef long long l;
typedef unsigned long long u;
#define l(i, x, n, c) for (u i = x; i < n; i += c)
#define t()   \
    l t;      \
    cin >> t; \
    while (t--)
#define in(n) \
    l n;      \
    cin >> n
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int count = 0;
    while (cin >> s)
    {
        l mask[s.length() + 1];
        mask[s.length()] = 0;
        for (int i = s.length() - 1; i >= 0; i--)
        {
            mask[i] = (mask[i + 1] | (1 << (s[i] - 'a')));
        }
        queue<l> q[26];
        l(i, 0, s.length(), 1)
        {
            q[s[i] - 'a'].push(i);
        }
        l x = mask[0];
        l c = __builtin_popcount(mask[0]);
        l p = 1, j = 0;
        while (p <= c)
        {
            l(i, 0, 26, 1)
            {
                if (q[i].empty())
                    continue;
                while (q[i].front() < j)
                {
                    q[i].pop();
                }
                l v = q[i].front();
                if ((mask[v] & x) == x)
                {
                    cout << (char)('a' + i);
                    x ^= (1 << i);
                    while (q[i].size())
                        q[i].pop();
                    j = (v + 1);
                    p++;
                    break;
                }
            }
        }
        cout << "\n";
        // cout << count << "\n";
    }
    return 0;
}