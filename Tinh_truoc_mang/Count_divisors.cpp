#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 1000007;
int n, cnt[2*nmax];
 
void cnt_divisor()
{
    for (int i = 1; i*i <= nmax; ++i)
    for (int j = i; j <= nmax/i; ++j)
    {
        cnt[i*j] += 1 + (i!=j);
    }
}
 
int main()
{
    cin >> n;
    cnt_divisor();
    cout << cnt[n] << '\n';
    return 0;
}
