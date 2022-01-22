#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

void findUsername(vector<string> &user)
{
    unordered_map<string, int> mp;

    for (int i = 0; i < user.size(); i++)
    {
        if (mp[user[i]] == 0)
            mp[user[i]] = 1;
        else
        {
            mp[user[i]] += 1;
            user[i] += to_string(mp[user[i]] - 1);
        }
    }
}

int main()
{
    IOS;

    vector<string> usernames;

    usernames.push_back("a");
    usernames.push_back("a1");
    usernames.push_back("b");
    usernames.push_back("a");
    usernames.push_back("a");
    usernames.push_back("a");
    usernames.push_back("a");
    usernames.push_back("b");
    usernames.push_back("b1");
    usernames.push_back("b");
    usernames.push_back("b1");
    usernames.push_back("b1");

    findUsername(usernames);

    for (auto name : usernames)
        cout << name << endl;

    return 0;
}