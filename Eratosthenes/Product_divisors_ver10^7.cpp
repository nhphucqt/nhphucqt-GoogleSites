#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int nmax = 10000007;
int min_d[2*nmax];
int t, n;

void min_divisor() // Tinh truoc uoc nguyen to nho nhat
{
    for (int i = 2; i <= nmax; ++i) min_d[i] = i;
    for(int i = 2; i*i <= nmax; ++i)
        if(min_d[i] == i)
            for(int j = i; j <= nmax/i; ++j)
                if(min_d[i*j] == i*j) min_d[i*j] = i;
}

int cnt_d(int x) // Dem so uoc cua x
{
    int cnt = 1;
    while(x > 1)
    {
        int y = min_d[x];
        int p = 0;
        while(x % y == 0) { ++p; x /= y; }
        cnt *= (p+1);
    }
    return cnt;
}

int Pow(const int& a, const int& n) // Tinh luy thua a^n % MOD
{
    if (n == 0) return 1;
    if (n == 1) return a;
    long long tmp = Pow(a, n/2);
    if (n % 2 == 0) return tmp*tmp % MOD;
    else return tmp*tmp%MOD * a % MOD;
}

int product(const int& n) // Tinh tich uoc so cua n
{
    int x = cnt_d(n);
    long long p = Pow(n, x/2);
    if (x % 2 == 0) p = p * int(sqrt(n)) % MOD; // neu n^x la so chinh phuong (x chan)
    return p;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    min_divisor();
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << product(n) << '\n';
    }
    return 0;
}
