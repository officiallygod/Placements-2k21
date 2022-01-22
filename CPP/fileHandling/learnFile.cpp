#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream f;
    string data;

    f.open("abx.txt", ios::trunc | ios::in | ios::out);

    while (f)
    {
        getline(cin, data);

        if (data == "-1")
            break;

        f << data << endl;
    }

    f.seekg(0, ios::beg);

    while (f)
    {
        getline(f, data);

        cout << data << endl;
    }

    f.close();

    return 0;
}
