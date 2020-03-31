#include <bits/stdc++.h>
 
using namespace std;
 
long long n;
 
bool nt(long long n)
{
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); ++i)
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
