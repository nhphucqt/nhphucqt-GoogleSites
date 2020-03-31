#include <bits/stdc++.h>
 
using namespace std;
 
int n;
 
bool nt(int n)
{
    if (n < 2) return false;
    for (int i = 2; i <= n-1; ++i)
        if (n % i == 0) return false;
    return true;
}
 
int main()
{
    cin >> n;
    if (nt(n)) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
