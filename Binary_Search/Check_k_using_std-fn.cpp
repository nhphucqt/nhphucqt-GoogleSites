#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 1000007;
int n, k, a[nmax];
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    if (binary_search(a+1, a+n+1, k)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
