// MO's algorithm
#include <bits/stdc++.h>
#define fi first
#define se second
 
using namespace std;
 
struct item {
    int l, r, i;
};
 
const int N = 2e5+7;
int n, q;
vector<int> a;
vector<int*> tmp;
vector<item> que;
int cnt[N], ans[N], res;
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> q;
    a.resize(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        tmp.push_back(&a[i]);
    }
    sort(tmp.begin(),tmp.end(),[&](int*a,int*b) {
        return *a < *b;
    });
    int num = 0;
    for (int i = 0, last; i < tmp.size(); ++i) {
        if (i==0 || last != *tmp[i]) {
            last = *tmp[i];
            num++;
        }
        *tmp[i] = num;
    }
    for (int i = 1; i <= q; ++i) {
        int x, y;
        cin >> x >> y;
        que.push_back({x,y,i});
    }
    int C = sqrt(n);
    sort(que.begin(),que.end(),[&](item&a,item&b) {
        if (a.l/C != b.l/C) return a.l/C < b.l/C;
        return a.r < b.r;
    });
    int l = 1, r = 0;
    for (auto&q : que) {
        for (; l < q.l; res-=(--cnt[a[l]]==0),l++);
        for (; l > q.l; l--,res+=(++cnt[a[l]]==1));
        for (; r < q.r; r++,res+=(++cnt[a[r]]==1));
        for (; r > q.r; res-=(--cnt[a[r]]==0),r--);
        ans[q.i] = res;
    }
    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << '\n';
    }
    return 0;
}
