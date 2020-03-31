#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 11;
int n, ch[nmax];
bool used[nmax];
 
void print()
{
    for(int i = 1; i <= n; ++i) cout << ch[i] << ' ';
    cout << '\n';
}
 
void hv(int pos)
{
    for(int i = 1; i <= n; ++i)
    {
        if (!used[i])
        {
            ch[pos] = i;
            used[i] = true;
            if (pos == n) print();
            else hv(pos+1);
            used[i] = false;
        }
    }
}
 
int main()
{
    ios_base::sync_with_stdio(0); cout.tie(0);
    cin >> n;
    hv(1);
    return 0;
}
