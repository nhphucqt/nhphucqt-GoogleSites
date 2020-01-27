#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int Cal(ll n, ll k, int MOD)
{
    if (k == 0) return 1;
    if (k == 1) return (1 + n) % MOD;
    if (k % 2 != 0) return (1+n)*Cal(n*n%MOD, (k-1)/2, MOD) % MOD;
    else return (1 + n*(1+n)%MOD * Cal(n*n%MOD, (k-2)/2, MOD)) % MOD;
}

string To_str(int n)
{
    string s = "";
    while (n > 0)
    {
        s = char(n%10 + 48) + s;
        n /= 10;
    }
    while (s.size() < 3) s = "0" + s;
    return s;
}

void make_test(string ad)
{
    ofstream inp("Cal\\" + ad + "\\cal.inp");
    ofstream out("Cal\\" + ad + "\\cal.out");
    if (ad <= "050")
    {
        ll n = 1 + ll(pow(rand(), 4)) % ll(1e18);
        int k = ll(rand()*rand()) % int(1e6);
        int MOD = 1 + ll(rand()*rand()) % int(2e9);
        inp << n << ' ' << k << ' ' << MOD;
        out << Cal(n%MOD, k, MOD);
    }
    else if (ad <= "075")
    {
        int n = 1 + ll(rand()*rand()) % int(1e9);
        ll k = 1 + ll(pow(rand(), 4)) % ll(1e18);
        int MOD = 1e9+7;
        inp << n << ' ' << k << ' ' << MOD;
        out << Cal(n%MOD, k, MOD);
    }
    else
    {
        ll n = 1 + ll(pow(rand(), 4)) % ll(1e18);
        ll k = 1 + ll(pow(rand(), 4)) % ll(1e18);
        int MOD = 1 + ll(rand()*rand()) % int(2e9);
        inp << n << ' ' << k << ' ' << MOD;
        out << Cal(n%MOD, k, MOD);
    }
    inp.close();
    out.close();
}

int main()
{
    system("rd /s /q Cal");
    system("md Cal");
    for (int it = 1; it <= 100; ++it)
    {
        string ad = To_str(it);
        system(("md Cal\\" + ad).c_str());
        make_test(ad);
        cout << "Test " << it << ": Completed!\n";
    }
    return 0;
}
