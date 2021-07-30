#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

void compress(vector<int>&v) {
    vector<int> tmp = v;
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for (int i = 0; i < v.size(); ++i) {
        v[i] = lower_bound(tmp.begin(),tmp.end(),v[i]) - tmp.begin();
    }
}

void compress2(vector<int>&v) {
    int *tmp[v.size()];
    for (int i = 0; i < v.size(); ++i) {
        tmp[i] = &v[i];
    }
    sort(tmp,tmp+v.size(),[&](int*a,int*b) {
        return *a < *b;
    });
    int num = -1, last;
    for (int i = 0; i < v.size(); ++i) {
        if (i==0 || last != *tmp[i]) {
            last = *tmp[i]; num++;
        } 
        *tmp[i] = num;
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        v.push_back(x);
    }
    compress(v);
    for (int x : v) cout << x << ' ';
    return 0;
}
