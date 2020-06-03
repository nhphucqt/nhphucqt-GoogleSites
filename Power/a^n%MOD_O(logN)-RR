#include <bits/stdc++.h>

using namespace std;

long long a, n;
int MOD;

int Pow(int a, long long n, int MOD)
{
    long long x = a, res = 1;
    while (n > 0)
    {
        if (n&1) res = res * x % MOD;
        x = x * x % MOD; n /= 2;
    }
    return res;
}

int main()
{
    cin >> a >> n >> MOD;
    cout << Pow(a%MOD, n, MOD);
    return 0;
}
