#include <iostream>
#include <bits/stdc++.h>

using namespace std;

unordered_map<int, deque<int>> uni;

deque<int> getDivisors(int n)
{
    int i;
    deque<int> divisor;

    if (n == 1)
        return divisor;

    if (uni.find(n) != uni.end())
        return uni[n];

    for (i = 1; i * i < n; i++)
    {
        if (n % i == 0)
            divisor.push_back(i);
    }
    if (i - (n / i) == 1)
        i--;

    for (; i >= 1; i--)
        if (n % i == 0)
            divisor.push_back(n / i);

    sort(divisor.begin(), divisor.end());

    if (divisor.front() == 1)
        divisor.pop_front();

    if (divisor.back() == n)
        divisor.pop_back();

    uni[n] = divisor;
    return divisor;
}

int main()
{
    int n, val;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr.push_back(val);
    }

    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        while (num > 0)
        {
            deque<int> divisor = getDivisors(num);

            if (divisor.size() == 0)
                num = num - 1;
            else
                num = divisor.back();
            mx++;
        }

        cout << mx << endl;
        mx = 0;
    }

    return 0;
}