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

long long Pow(int a, int n)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    long long tmp = Pow(a, n/2);
    if (n % 2 == 0) return tmp * tmp;
    else return tmp*tmp*a;
}

int Cal(int a, int n)
{
    return (Pow(a, n+1) - 1) / (a - 1);
}

int sum_d(int n)
{
    int sum = 1;
    while (n > 1)
    {
        int p = min_d[n];
        int cnt = 0;
        for (; n % p == 0; ++cnt) n /= p;
        sum *= Cal(p, cnt);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    min_divisor();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << sum_d(n) << '\n';
    }
    return 0;
}
