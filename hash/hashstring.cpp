#include <bits/stdc++.h>

using namespace std;

const int NUMMOD = 1;
const long long MOD[] = {(int)1e9+2277, (int)1e9+5277, (int)1e9+8277, (int)1e9+9277};
const long long BASE = 311;

struct Hash {
    vector<long long> h[NUMMOD], p[NUMMOD];
    void init(const string &s) {
        int n = s.size();
        for (int i = 0; i < NUMMOD; ++i) {
            h[i].resize(n+1);
            p[i].resize(n+1);
            p[i][0] = 1;
            h[i][0] = 0;
            for (int j = 1; j <= n; ++j) {
                h[i][j] = (h[i][j-1] * BASE + s[j-1]) % MOD[i];
                p[i][j] = p[i][j-1] * BASE % MOD[i];
            }
        }
    }
    int getHashWithMod(int l, int r, int i) {
        l++; r++;
        return (h[i][r] - h[i][l-1] * p[i][r-l+1] + MOD[i]*MOD[i]) % MOD[i];
    }
    vector<int> getHash(int l, int r) {
        vector<int> gh;
        for (int i = 0; i < NUMMOD; ++i) {
            gh.push_back(getHashWithMod(l, r, i));
        }
        return gh;
    }
};

int main() {
    return 0;
}
