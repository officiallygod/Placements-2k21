#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findRange(int charge)
{
    if (charge >= 0 and charge <= 10)
        return 10;
    else if (charge >= 11 and charge <= 230)
        return 5;
    else if (charge >= 231 and charge <= 559)
        return 8;
    else if (charge >= 560 and charge <= 1009)
        return 2;
    else if (charge >= 1010 and charge <= 5000)
        return 7;
    else if (charge >= 5001 and charge <= 10000)
        return 8;
    else
        return 3;
}

int main()
{
    int test;
    cin >> test;
    while (test)
    {
        int s, t, cnt = 0;
        cin >> s >> t;
        if (s == t)
        {
            cout << cnt << endl;
        }
        else
        {
            while (s < t)
            {
                int add = findRange(s);
                s += add;
                cnt++;
            }
            cout << cnt << endl;
        }
        test--;
    }
    return 0;
}