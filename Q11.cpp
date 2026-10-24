#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    const long long MOD = 1000000007;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum = (sum + arr[i]) % MOD;
    }

    cout << sum;

    return 0;
}
