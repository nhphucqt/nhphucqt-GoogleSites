#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 10000007;
int n, min_d[nmax*2];
 
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
    min_divisor();
    cin >> n;
    cout << min_d[n];
    return 0;
}
