#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int ans = factorial(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i - 1])
        {
            ans += factorial(arr[i] - 1);
        }
        else
        {
            ans += factorial(arr[i]);
        }
    }

    cout << ans;
    return 0;
}