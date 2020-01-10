#include <bits/stdc++.h>
#define P first
#define N second
 
using namespace std;
 
const int nmax = 10000007;
int n, min_d[nmax*2];
 
void min_divisor() // Tinh truoc uoc nguyen to nho nhat
{
    for (int i = 2; i <= nmax; ++i) min_d[i] = i;
    for (int i = 2; i*i <= nmax; ++i)
    {
        if (min_d[i] == i)
            for (int j = i; j <= nmax/i; ++j)
            {
                if (min_d[i*j] == i*j) min_d[i*j] = i;
            }
    }
}
 
vector<pair<int,int>> phantich(int n) // Phan tich n thanh thua so nguyen to
{
    vector<pair<int,int>> unt;
    while (n > 1)
    {
        unt.push_back({min_d[n], 0});
        for (; unt.back().P == min_d[n]; n /= min_d[n], ++unt.back().N);
    }
    return unt;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    min_divisor();
    cin >> n;
    auto pt = phantich(n);
    for (auto x : pt) cout << x.P << ' ' << x.N << '\n';
    return 0;
}
