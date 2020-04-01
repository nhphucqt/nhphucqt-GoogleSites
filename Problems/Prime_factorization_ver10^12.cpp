#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
ll n;

ll min_d(ll n, ll p)
{
    for (ll i = p; i*i <= n; ++i)
        if (n % i == 0) return i;
    return n;
}

vector<pair<ll,int>> factorize(ll n)
{
    vector<pair<ll, int>> f;
    ll p = 2;
    while (n > 1)
    {
        p = min_d(n, p);
        for (f.push_back({p, 0}); n % p == 0; ++f.back().Y) n /= p;
    }
    return f;
}

int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    auto f = factorize(n);
    for (auto p : f) cout << p.X << ' ' << p.Y << '\n';
    return 0;
}
