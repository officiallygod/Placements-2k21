#include <bits/stdc++.h>
using namespace std;

int marathon(int input1, int input2, int input3[])
{
    sort(input3, input3 + input1);
    int sum = 0;
    int n = input1 - 1;
    for (int i = 0; i < input2; i++)
    {
        sum += input3[n];
        n--;
    }
    return sum;
}

int main()
{
    int arr[4] = {4, 1, 2, 5};
    int res = marathon(4, 2, arr);
    cout << res << endl;
    return 0;
}