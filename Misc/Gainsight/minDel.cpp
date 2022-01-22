#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> num;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        num.push_back(val);
    }

    int cnt = 0, chck = 0;

    for (int i = 0; i < n - 1; i++)
    {
        if (num[i] > num[i + 1])
        {
            cnt++;
            if (num[i] - 1 <= num[i + 1])
                chck++;
        }
    }

    if (cnt <= 1)
    {
        if (chck == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
        cout << "No" << endl;

    return 0;
}