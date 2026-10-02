#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n != 0)
    {
        int h = n % 10;

        if (h % 2 == 0)
            h = 0;

        cout << h;

        n = n / 10;
    }

    return 0;
}
