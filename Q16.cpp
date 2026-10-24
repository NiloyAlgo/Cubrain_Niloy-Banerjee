#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int scores[n];

    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    int first = 0, second = 0;
    bool hasFirst = false, hasSecond = false;

    for (int i = 0; i < n; i++)
    {
        if (!hasFirst || scores[i] > first)
        {
            if (hasFirst)
            {
                second = first;
                hasSecond = true;
            }

            first = scores[i];
            hasFirst = true;
        }
        else if (scores[i] != first &&
                 (!hasSecond || scores[i] > second))
        {
            second = scores[i];
            hasSecond = true;
        }
    }

    if (hasSecond)
    {
        cout << second;
    }
    else
    {
        cout << -1;
    }

    return 0;
}
