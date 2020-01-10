#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 10000007;
int n;
bool nt[nmax*2];
 
void Eratosthenes()
{
    fill(nt+2, nt+nmax+1, true);
    for (int i = 2; i*i <= nmax; ++i)
    {
        if (nt[i])
            for (int j = i; j <= nmax/i; ++j)
            {
                nt[i*j] = false;
            }
    }
}
 
int main()
{
    Eratosthenes();
    cin >> n;
    if (nt[n]) cout << n << " la so nguyen to\n";
    else cout << n << " khong phai la so nguyen to\n";
    return 0;
}
