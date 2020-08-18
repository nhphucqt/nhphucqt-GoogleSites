#include <bits/stdc++.h>

using namespace std;

int modulo(string &s, int MOD) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        res = (10ll*res%MOD + (s[i]-48)) % MOD;
    }
    return res;
}

int Pow(int a, int n, int MOD) {
    int res = 1;
    for (; n>0; a=1ll*a*a%MOD, n>>=1) {
        if (n&1) res = 1ll*res*a%MOD;
    }
    return res;
}

int Pow_s(string &sa, string &b, int MOD) {
    int res = 1;
    int a = modulo(sa, MOD);
    for (int i = 0; i < b.size(); ++i) {
        res = 1ll * Pow(res,10,MOD) * Pow(a,b[i]-48,MOD) % MOD;
    }
    return res;
}

int main() {
    string a, b;
    int MOD;
    cin >> a >> b;
    cin >> MOD;
    cout << Pow_s(a, b, MOD);
    return 0;
}
