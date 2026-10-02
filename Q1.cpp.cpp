#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count = 0;
    bool flag = false;

    if (n < 0)
        n = -n;

    while (n != 0)
    {
        count++;
        n = n / 10;
    }

    if (count % 2 == 0)
        flag = true;
    else
        flag = false;

    if (flag == true)
        cout << "true";
    else
        cout << "false";

    return 0;
}
