#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define IOS ios::sync_with_stdio(0);

int main()
{
    IOS;
    vector<string> misspelled = {"Science", "sicence", "science", "departmnet", "department", "computer", "comptuer", "Science"};
    vector<string> correct = {"department", "computer", "science"};
    string search = "sicence";

    vector<vector<string>> ans;

    for (string val : correct)
    {
        string valS = val;
        sort(valS.begin(), valS.end());

        vector<string> temp;

        for (string other : misspelled)
        {
            string otherS = other;
            sort(otherS.begin(), otherS.end());

            if (valS.compare(otherS) == 0)
                temp.push_back(other);
        }

        // temp.push_back(val);
        ans.push_back(temp);
    }

    for (auto val : ans)
    {
        for (auto other : val)
        {
            cout << other << "  ";
        }
        cout << endl;
    }

    for (string val : correct)
    {
        string searchS = search;
        sort(searchS.begin(), searchS.end());

        string valS = val;
        sort(valS.begin(), valS.end());

        if (searchS.compare(valS) == 0)
        {
            cout << "The correct spelling of " << search << " is " << val << endl;
            break;
        }
    }

    return 0;
}