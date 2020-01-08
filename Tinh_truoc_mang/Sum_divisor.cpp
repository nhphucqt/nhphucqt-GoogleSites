#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 1000007;
int n, sum[2*nmax];
 
void sum_divisor()
{
    for (int i = 1; i*i <= nmax; ++i)
    for (int j = i; j <= nmax/i; ++j)
    {
        sum[i*j] += i + j*(i!=j);
    }
}
 
int main()
{
    cin >> n;
    sum_divisor();
    cout << sum[n] << '\n';
    return 0;
}