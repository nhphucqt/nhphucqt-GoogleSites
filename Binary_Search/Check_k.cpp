#include <bits/stdc++.h>
 
using namespace std;
 
int n, a[1000007], k;
 
bool found(int k)
{
    int d = 1;
    int c = n;
    while (d <= c)
    {
        int g = (d+c)/2;
        if (a[g] == k) return true;
        else if (a[g] < k) d = g+1;
        else c = g-1;
    }
    return false;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    if (found(k)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
