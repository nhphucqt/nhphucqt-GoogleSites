#include <bits/stdc++.h>

using namespace std;

vector<int> Zfunc(const string &s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = max(0, min(z[i-x], y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}

int main() {
    string s;
    cin >> s;
    vector<int> z = Zfunc(s);
    for (int i = 0; i < z.size(); ++i) {
        cout << z[i] << ' ';
    }
    return 0;
}
