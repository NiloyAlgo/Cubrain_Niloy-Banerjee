#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    int target = 0;
    int target2 = 0;

    while (n != 0)
    {
        int h = n % 10;

        if (a == h)
            target++;
        else if (b == h)
            target2++;

        n = n / 10;
    }

    int g = abs(target - target2);

    cout << g;

    return 0;
}
