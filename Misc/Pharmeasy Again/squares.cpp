#include <bits/stdc++.h>
using namespace std;

int findSumLength(vector<int> arr, int n)
{
    map<int, int> freq;

    for (int i : arr)
        freq[i] += 1;

    map<int, int, greater<int>> freq_2;
    map<int, int, greater<int>> freq_4;

    for (auto i : freq)
    {
        if (freq[i.first] >= 2)
            freq_2[i.first] = freq[i.first];

        if (freq[i.first] >= 4)
            freq_4[i.first] = freq[i.first];
    }

    int ans_4 = 0, ans_2 = 0;
    int val_4 = freq_4.begin()->first;

    ans_4 = val_4 * 4;
    freq_2[val_4] = freq_2[val_4] - 4;

    if (freq_2[val_4] < 2)
        freq_2.erase(val_4);

    int rec1 = 0, rec2 = 0;

    for (auto i : freq_2)
    {
        if (rec1 != 0 and rec2 != 0)
            break;

        if (rec1 == 0)
        {
            rec1 = i.first;
        }
        else if (rec1 != 0 and rec2 == 0)
        {
            rec2 = i.first;
        }
    }
    ans_2 = rec1 * 2 + rec2 * 2;
    return (ans_2 + ans_4);
}

int main()
{
    vector<int> arr = {5, 5, 5, 5, 5, 5, 3, 3, 4, 4, 4, 6, 6};
    int n = arr.size(), ans = 0;
    ans = findSumLength(arr, n);
    cout << ans << endl;
    return 0;
}
