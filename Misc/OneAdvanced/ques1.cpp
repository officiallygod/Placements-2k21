#include <bits/stdc++.h>
using namespace std;

#define OUT 0
#define IN 1

int countWords(string str)
{
    int state = OUT;
    int i = 0;
    int wc = 0;
    while (i < str.length())
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '?' || isdigit(str[i]))
            state = OUT;
        else if ((str[i] - 1) != ' ' and str[i] == '[' || str[i] == ']' || str[i] == '(' || str[i] == ')')
            wc--;
        else if (state == OUT)
        {
            state = IN;
            ++wc;
        }
        cout << str[i] << " : " << wc << endl;
        ++i;
    }

    return wc;
}

// Driver code
int main(void)
{
    char str[] = "he is a good progammer, hew won 865 competitions, but sometimes he dont. What do you think? All test-cases should pass. Done-done?";
    char str3[] = "How many eggs are in a half-dozen, 13?";
    char str4[] = "I love my country";
    char str2[] = "jds dsaf lkdf kdsa fkldsf, adsbf ldka ads? asd bfal ds bf[l. afk dhj ds 878  dwa WE DE 7475 dsfh ds RAMU 78 dj.";
    string abc;
    getline(cin, abc);
    cout << countWords(abc) << endl;
    return 0;
}