#include <bits/stdc++.h>
 
using namespace std;
 
const long long MOD = 1000000007;
int a, n, m;
 
int Pow(int a, int n, int MOD)
{
    if (n == 0) return 1;
    long long tmp = Pow(a, n/2, MOD);
    if (n % 2 == 0) return tmp*tmp % MOD;
    else return (tmp*tmp)%MOD * a % MOD;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> a >> n >> m;
    cout << Pow(a, Pow(n, m, MOD-1), MOD) << '\n';
    return 0;
}
