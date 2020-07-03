#include <bits/stdc++.h>

using namespace std;

template<typename T>
inline read(T &x)
{
    bool neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') neg = !neg;
    x = c-48;
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x*10 + (c-48);
    if (neg) x = -x;
}

template<typename T>
inline write(T x)
{
    if (x < 0) { putchar('-'); x = -x; }
    T tmp = x/10, de = 1;
    while (tmp > 0) { de *= 10; tmp /= 10; }
    while (de > 0) { putchar(x/de+48); x %= de; de /= 10; }
}

template<typename T>
inline writeln(T x)
{
    write(x);
    putchar('\n');
}

const int N = 1e7+7;
int n, a[N];

int main()
{
    read(n);
    for (int i = 1; i <= n; ++i)
    {
        read(a[i]);
        writeln(a[i]);
    }
    return 0;
}
