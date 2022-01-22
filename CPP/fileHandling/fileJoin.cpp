#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream f1, f2, f3;
    string data;

    f1.open("abx.txt", ios::in);
    f2.open("abxx.txt", ios::in);
    f3.open("abxxx.txt", ios::trunc | ios::out);

    f1.seekg(0, ios::beg);
    f2.seekg(0, ios::beg);

    while (f1)
    {
        getline(f1, data);

        if (data != "")
            f3 << data << endl;
    }

    while (f2)
    {
        getline(f2, data);

        if (data != "")
            f3 << data << endl;
    }

    f1.close();
    f2.close();
    f3.close();

    return 0;
}
