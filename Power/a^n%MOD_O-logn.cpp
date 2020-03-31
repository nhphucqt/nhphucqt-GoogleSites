#include <bits/stdc++.h>
 
using namespace std;
 
long long a, n;
int MOD;
 
int Pow(long long a, long long n, int MOD)
{
    if (n == 0) return 1;
    if (n == 1) return a;
    long long tmp = Pow(a%MOD, n/2, MOD);
    if (n % 2 == 0) return tmp*tmp % MOD;
    else return (tmp*tmp)%MOD * a % MOD;
}
 
int main()
{
    cin >> a >> n >> MOD;
    cout << Pow(a%MOD, n, MOD);
    return 0;
}
