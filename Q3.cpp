#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int original = n;
    int rev = 0;

    while (n != 0)
    {
        int h = n % 10;
        rev = rev * 10 + h;
        n = n / 10;
    }

    if (original == rev)
        cout << original;
    else
        cout << original + rev;

    return 0;
}
