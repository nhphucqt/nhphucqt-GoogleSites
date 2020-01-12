#include <bits/stdc++.h>

using namespace std;

const int nmax = 10000007;
int min_d[nmax*2];
int t, n;

void min_divisor()
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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    min_divisor();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << min_d[n] << '\n';
    }
    return 0;
}
