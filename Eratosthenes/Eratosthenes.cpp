#include <bits/stdc++.h>

using namespace std;

const int nmax = 10000007;
bool nt[nmax*2];
int t, n;

void Eratosthenes()
{
    fill(nt+2, nt+nmax+1, true);
    for (int i = 2; i*i <= nmax; ++i)
        if (nt[i])
            for (int j = i; j <= nmax/i; ++j)
                nt[i*j] = false;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    Eratosthenes();
    cin >> t;
    while (t--)
    {
        cin >> n;
        nt[n] ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
