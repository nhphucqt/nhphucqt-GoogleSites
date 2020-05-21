#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e7+7;
int max_d[nmax+1], min_d[nmax+1];
int t, n;

void max_divisor()
{
    for (int i = 2; i <= nmax; ++i) max_d[i] = i;
    for (int i = 2; i*i <= nmax; ++i)
        if (max_d[i] == i)
            for (int j = i; j <= nmax/i; ++j)
                if (i < max_d[j]) max_d[i*j] = max_d[j];
                else max_d[i*j] = i;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    max_divisor();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << max_d[n] << '\n';
    }
    return 0;
}
