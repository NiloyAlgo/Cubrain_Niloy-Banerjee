#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int sales[n];

    for (int i = 0; i < n; i++)
    {
        cin >> sales[i];
    }

    int threshold;
    cin >> threshold;

    for (int i = 0; i < n; i++)
    {
        if (sales[i] >= threshold)
        {
            cout << sales[i] << " ";
        }
    }

    return 0;
}
