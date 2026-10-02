#include <iostream>
using namespace std;

int reverse_and_double(int n)
{
    int rev = 0;
    int sign = 1;

    if (n < 0)
    {
        sign = -1;
        n = -n;
    }

    while (n != 0)
    {
        int h = n % 10;
        rev = rev * 10 + h;
        n = n / 10;
    }

    return sign * rev * 2;
}

int main()
{
    int n;
    cin >> n;

    cout << reverse_and_double(n);

    return 0;
}
