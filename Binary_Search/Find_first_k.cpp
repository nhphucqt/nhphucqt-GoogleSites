#include <bits/stdc++.h>
#define V first    // valua
#define P second   // pos
 
using namespace std;
 
const int nmax = 1000007;
int n, k;
pair<int,int> a[nmax];
 
int pos_k(const int& k)
{
    int d = 1;
    int c = n;
    if (a[d].V >= k) return a[d].P;
    while (d < c)
    {
        int g = (d+c+1) / 2;
        if (a[g].V < k) d = g;
        else c = g-1;
    }
    if (c == n || a[c+1].V != k) return -1;
    return a[c+1].P;
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
    int p = pos_k(k);
    if (p != -1) cout << p << '\n';
    else cout << "NOT EXISTS!\n";
    return 0;
}
