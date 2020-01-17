#include <bits/stdc++.h>

using namespace std;

const int nmax = 1000007;
int cnt_d[2*nmax];
int t, n;

void cnt_divisor()
{
    for (int i = 1; i*i <= nmax; ++i)
    for (int j = i; j <= nmax/i; ++j)
    {
        cnt_d[i*j] += 1 + (i!=j);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cnt_divisor();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << cnt_d[n] << '\n';
    }
    return 0;
}
