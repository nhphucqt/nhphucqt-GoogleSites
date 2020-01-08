#include <bits/stdc++.h>
#define V first    // valua
#define P second   // pos
 
using namespace std;
 
const int nmax = 1000007;
int n, k;
pair<int,int> a[nmax];
 
int upper(const int& k)
{
    int d = 1;
    int c = n;
    if (a[d].V > k) return d; // if (a[d].V >= k) return d;             *
    while (d < c)
    {
        int g = (d+c+1) / 2;
        if (a[g].V <= k) d = g; // if (a[g].V < k) d = g;               **
        else c = g-1;
    }
    if (c == n) return -1;
    return c+1;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].V;
        a[i].P = i;
    }
    sort(a+1,a+n+1);
    int p = upper(k);
    if (p != -1)
    {
        cout << "Valua: " << a[p].V << '\n';
        cout << "Pos:   " << a[p].P << '\n';
    }
    else cout << "NOT EXISTS!\n";
    return 0;
}
