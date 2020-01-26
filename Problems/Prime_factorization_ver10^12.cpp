#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;

typedef long long ll;
ll n;

ll min_d(ll n)
{
    if (n < 2) return 1;
    if (n % 2 == 0) return 2;
    if (n % 3 == 0) return 3;
    for (long long i = 5; i*i <= n; i+=6)
    {
        if (n % i == 0) return i;
        if (n % (i+2) == 0) return i+2;
    }
    return n;
}

vector<pair<ll,int>> factorize(ll n)
{
    vector<pair<ll, int>> f;
    while (n > 1)
    {
        long long p = min_d(n);
        for (f.push_back({p, 0}); n % p == 0; ++f.back().Y) n /= p;
    }
    return f;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    auto f = factorize(n);
    for (auto p : f) cout << p.X << ' ' << p.Y << '\n';
    return 0;
}
