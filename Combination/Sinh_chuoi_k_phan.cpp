#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 100;
int n, k, ch[nmax];
 
void print()
{
    for(int i = 1; i <= n; ++i) cout << ch[i] << ' ';
    cout << '\n';
}
 
void chon(int pos)
{
    for (int i = 0; i <= k-1; ++i)
    {
        ch[pos] = i;
        if (pos == n) print();
        else chon(pos+1);
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);
    cin >> k >> n;
    chon(1);
    return 0;
}
