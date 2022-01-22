#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int mxCnt1 = 0;
    int mxCnt2 = 0;
    string str;
    bool ans = false;
    cin >> str;

    for (auto player : str)
    {
        if (player == '1')
            mxCnt1++;
        else
            mxCnt1 = 0;

        if (player == '0')
            mxCnt2++;
        else
            mxCnt2 = 0;

        if (mxCnt2 >= 7)
            ans = true;

        if (mxCnt1 >= 7)
            ans = true;
    }

    if (ans)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
