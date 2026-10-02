#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int b = 1;
    int g = 0;

    while (n != 0)
    {
        int h = n % 10;

        b = b * h;
        g = g + h;

        n = n / 10;
    }

    cout << abs(b - g);

    return 0;
}
