#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool solve(int n, string a, string b, string c)
{
    int ans = -1;
    if (a == b)
        return true;
    for (int i = 0; i < n; i++)
    {
        char x = a[i];
        char y = b[i];
        char z = c[i];

        if (x == y && y == z)
            continue;
        else if (x == y || y == z || x == z)
        {
            ans++;
        }
    }
    return (ans < 0) ? false : true;
}

int main()
{
    string a;
    string b;
    string c;
    cin >> a >> b >> c;
    int n = a.size();
    if (solve(n, a, b, c))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}