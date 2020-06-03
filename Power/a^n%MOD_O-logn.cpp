#include <bits/stdc++.h>

using namespace std;

long long a, n;
int MOD;

int Pow(int a, long long n, int MOD)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    long long tmp = Pow(a, n/2, MOD);
    tmp = tmp * tmp % MOD;
    if (n&1) tmp = tmp * a % MOD;
    return tmp;
}

int main()
{
    cin >> a >> n >> MOD;
    cout << Pow(a%MOD, n, MOD);
    return 0;
}
