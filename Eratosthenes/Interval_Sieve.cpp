#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int nmax = 1e7+7;
bool nt[nmax];
int t;
ll L, R, n;

void interval_sieve(ll L, ll R)
{
    fill(nt, nt+R-L+1, true);
    for (ll i = 2; i*i <= R; ++i)
    for (ll j = max((L+i-1)/i, i); j <= R/i; ++j)
        nt[i*j-L] = false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> L >> R;
    interval_sieve(L, R);
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << nt[n-L] << '\n';
    }
    return 0;
}
