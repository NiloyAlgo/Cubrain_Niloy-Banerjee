#include <stdio.h>

#define MOD 1000000007LL

int main(void)
{
    int n;
    scanf("%d", &n);

    long long sum = 0;
    long long value;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &value);
        sum = (sum + value % MOD) % MOD;
    }

    printf("%lld\n", sum);

    return 0;
}
