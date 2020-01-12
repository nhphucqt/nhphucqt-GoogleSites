#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int nmax = 1000007;
const int MOD = 1000000007;
int product[2*nmax];
int t, n;

void product_divisor()
{
    fill(product+1, product+nmax+1, 1);
    for (int i = 1; i*i <= nmax; ++i)
    {
        product[i*i] = (ll)product[i*i] * i % MOD;
        for (int j = i+1; j <= nmax/i; ++j)
            product[i*j] = (ll)product[i*j] * i % MOD * j % MOD;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    product_divisor();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << product[n] << '\n';
    }
    return 0;
}
