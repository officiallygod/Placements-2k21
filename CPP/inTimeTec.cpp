#include <bits/stdc++.h>
using namespace std;

void printEqualModNumbers(vector<int> arr, int n)
{

    sort(arr.begin(), arr.end());

    int d = arr[n - 1] - arr[0];

    if (d == 0)
    {
        cout << "Infinite solution";
        return;
    }

    vector<int> v;
    for (int i = 1; i * i <= d; i++)
    {
        if (d % i == 0)
        {
            v.push_back(i);
            if (i != d / i)
                v.push_back(d / i);
        }
    }
    if (v[0] == 1)
        v.erase(v.begin());

    for (int i = 0; i < v.size(); i++)
    {
        int temp = arr[0] % v[i];

        int j;
        for (j = 1; j < n; j++)
            if (arr[j] % v[i] != temp)
                break;

        if (j == n)
            cout << v[i] << " ";
    }
}

int main()
{
    int n, val;
    vector<int> vc;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        vc.push_back(val);
    }
    printEqualModNumbers(vc, n);
    return 0;
}
