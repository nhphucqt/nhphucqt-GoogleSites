#include <bits/stdc++.h>
 
using namespace std;
 
int a, n, MOD;
 
int Pow(const int& a, const int& n, const int& MOD)
{
    long long p = 1;
    for (int i = 1; i <= n; ++i)
    {
        p = p * a % MOD;
    }
    return p;
}
 
int main()
{
    cin >> a >> n >> MOD;
    cout << Pow(a, n, MOD);
    return 0;
}
