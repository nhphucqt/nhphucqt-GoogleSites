#include <bits/stdc++.h>

using namespace std;

const int inf = 2e9;

struct Interval_tree
{
    int n;
    vector<int> node;
    Interval_tree(int n, int val): n(n), node(4*n, val) {}
    void update_(int id, int l, int r, int i, int val)
    {
        if (i<l||i>r) return;
        if (l==r) { node[id] = val; return; }
        int m = (l+r)>>1;
        update_(id<<1, l, m, i, val);
        update_(id<<1|1, m+1, r, i, val);
        node[id] = max(node[id<<1],node[id<<1|1]);
    }
    void update(int i, int val)
    {
        update_(1, 1, n, i, val);
    }
    int get_(int id, int l, int r, int x, int y)
    {
        if (l>y||r<x) return -inf;
        if (l>=x&&r<=y) return node[id];
        int m = (l+r)>>1;
        return max(get_(id<<1,l,m,x,y),get_(id<<1|1,m+1,r,x,y));
    }
    int get(int x, int y)
    {
        return get_(1, 1, n, x, y);
    }
};

int main()
{
    Interval_tree it(1e5, 0);
    int t;
    cin >> t;
    while (t--)
    {
        int k, x, y;
        cin >> k >> x >> y;
        if (!k) it.update(x, y);
        else cout << it.get(x, y) << '\n';
    }
    return 0;
}
