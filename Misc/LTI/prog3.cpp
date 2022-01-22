#include <bits/stdc++.h>
using namespace std;

int minPenalty(int input1, int input2[])
{
    sort(input2, input2 + input1);
    int sum = 0;
    for (int i = 0; i < input1 - 1; i++)
    {
        sum += abs(input2[i] - input2[i + 1]);
    }

    return sum;
}

int main()
{
    int arr[3] = {1, 3, 2};
    int res = minPenalty(3, arr);
    cout << res << endl;
    return 0;
}