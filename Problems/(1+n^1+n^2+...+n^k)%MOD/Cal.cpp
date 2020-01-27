#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, k;
int MOD;

int Pow(int a, ll n, int MOD)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    ll tmp = Pow(a, n/2, MOD);
    if (n % 2 == 0) return tmp*tmp % MOD;
    else return tmp*tmp%MOD * a % MOD;
}

int inv(ll n, int MOD)
{
    return (Pow(n%MOD, MOD-2, MOD));
}

int Cal(ll n, ll k)
{
    if (k == 0) return 1;
    if (k == 1) return (1 + n) % MOD;
    if (k % 2 != 0) return (1+n)*Cal(n*n%MOD, (k-1)/2) % MOD;
    else return (1 + n*(1+n)%MOD * Cal(n*n%MOD, (k-2)/2)) % MOD;
}

int sub1()
{
    ll ans = 0;
    ll p = 1;
    for (int i = 0; i <= k; i++)
    {
        ans = (ans + p) % MOD;
        p = p * (n%MOD) % MOD;
    }
    return ans;
}

int sub2()
{
    if (n == 1) return (k + 1) % MOD;
    int ans = (ll)(Pow(n%MOD, k+1, MOD) - 1) % MOD * inv(n-1, MOD) % MOD;
    if (ans < 0) ans += MOD;
    return ans;
}

int sub3()
{
    return Cal(n%MOD, k);
}

void scan()
{
    cin >> n >> k >> MOD;
}

int main()
{
    scan();
    cout << sub3();
    return 0;
}
