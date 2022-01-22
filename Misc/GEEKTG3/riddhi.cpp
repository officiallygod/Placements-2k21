#include <bits/stdc++.h>
using namespace std;

vector<int> primes = {3, 5, 7};

void solve(string str)
{
    int oddSum = 0, evenSum = 0;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = tolower(str[i]);
        if (i % 2 == 0)
            evenSum += ch;
        else
            oddSum += ch;
    }
    // cout << oddSum << " " << evenSum << endl;
    int diff = abs(oddSum - evenSum);

    for (int val : primes)
    {
        if (diff % val == 0)
        {
            cout << "Prime String" << endl;
            return;
        }
    }

    cout << "Casual String" << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        solve(str);
    }

    return 0;
}