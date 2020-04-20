#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
int n, m, Fa[N];

int Findroot(int u) // O(logn)
{
    if (Fa[u] < 0) return u;
    return Fa[u] = Findroot(Fa[u]);
}

void Unionroot(int u, int v) // O(1) -- u, v are roots
{
    int t = Fa[u] + Fa[v];
    if (Fa[u] <= Fa[v]) { Fa[v] = u; Fa[u] = t; }
    else { Fa[u] = v; Fa[v] = t; }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(Fa, -1, sizeof Fa);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
    {
        int x, y;
        cin >> x >> y;
        int u = Findroot(x);
        int v = Findroot(y);
        if (u != v) Unionroot(u, v);
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (Fa[i] < 0) cnt++;
    cout << "Number of sets: " << cnt << '\n';
    for (int i = 1; i <= n; ++i)
        cout << i << ' ' << Fa[i] << '\n';
    return 0;
}
