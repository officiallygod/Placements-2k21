#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int height = 0;
bool primer[100005];
void SieveOfEratosthenes(int n)
{
    memset(primer, true, sizeof(primer));
    for (int p = 2; p * p <= n; p++)
    {
        if (primer[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                primer[i] = false;
        }
    }
}
void solve(int n)
{
    if (n == 2)
        return;
    if (primer[n])
        return;
    int d = 0;
    for (int i = 2; i <= 7; i++)
    {
        if ((n % i) == 0 and (n / i) != 1)
        {
            height++;
            d = i;
            break;
        }
    }
    solve(n / d);
}

int main()
{
    int n = 99;
    SieveOfEratosthenes(n);
    solve(n);
    cout << height;
    return 0;
}