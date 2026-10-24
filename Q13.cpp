#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long arr[n > 0 ? n : 1];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    long long k;
    cin >> k;

    k = llabs(k);

    if (k == 0)
        return 0;

    long long sum = 0;
    bool found = false;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum % k == 0)
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "True";
    else
        cout << "False";

    return 0;
}
