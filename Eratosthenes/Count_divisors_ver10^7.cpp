#include <bits/stdc++.h>

using namespace std;

const int nmax = 1e7+7;
int min_d[2*nmax];
int t, n;

void min_divisor()
{
    for (int i = 2; i <= nmax; ++i) min_d[i] = i;
    for (int i = 2; i*i <= nmax; ++i)
        if (min_d[i] == i)
            for (int j = i; j <= nmax/i; ++j)
                if (min_d[i*j] == i*j) min_d[i*j] = i;
}

int cnt_d(int n)
{
    int ans = 1;
    while (n > 1)
    {
        int p = min_d[n];
        int cnt = 0;
        while (n % p == 0) { n /= p; cnt++; }
        ans *= cnt+1;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    min_divisor();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << cnt_d(n) << '\n';
    }
    return 0;
}
