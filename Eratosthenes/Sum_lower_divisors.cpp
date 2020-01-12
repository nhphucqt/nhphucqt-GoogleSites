#include <bits/stdc++.h>

using namespace std;

const int nmax = 1000007;
int sum[2*nmax];
int t, n;

void sum_divisor()
{
    fill(sum+2, sum+nmax+1, 1);
    for (int i = 2; i*i <= nmax; ++i)
    for (int j = i; j <= nmax/i; ++j)
    {
        sum[i*j] += i + j*(i!=j);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sum_divisor();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << sum[n] << '\n';
    }
    return 0;
}
