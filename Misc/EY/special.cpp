#include <bits/stdc++.h>
#define inf 1000000007
using namespace std;
typedef long long ll;
int main()
{
    ll t, cases = 0;
    cin >> t;
    while (t--)
    {
        printf("Case #%lld:\n", ++cases);
        ll n, q;
        cin >> n >> q;
        ll a[n];
        memset(a, 0, sizeof(a));
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        vector<ll> v;
        for (ll i = 1; i <= n; i++)
        {
            for (ll j = 0; j < n; j++)
            {
                ll sum = 0;
                if (j + i > n)
                    break;
                for (ll k = j; k < j + i && k < n; k++)
                {
                    sum += a[k];
                }
                v.push_back(sum);
            }
        }
        sort(v.begin(), v.end());
        while (q--)
        {
            ll start, end, ans = 0;
            cin >> start >> end;
            for (ll i = start - 1; i < end; i++)
            {
                ans += v[i];
            }
            cout << ans << endl;
        }
    }
    return 0;
}