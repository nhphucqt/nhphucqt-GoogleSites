#include <bits/stdc++.h>

using namespace std;

uint64_t mul5(uint64_t a, uint64_t b, uint64_t m) {
    auto res = (unsigned __int128) a * b % m;
    return (uint64_t) res;
}

uint64_t mul6(uint64_t a, uint64_t b, uint64_t m)
{
    if (a >= m) a %= m;
    if (b >= m) b %= m;
    uint64_t q = (long double) a * b / m;
    uint64_t r = a * b - q * m;
    return r;
}

int main() {
    freopen("output.txt", "w", stdout);
    uint64_t limit = 1e16;
    mt19937_64 ra;
    ra.seed(time(nullptr));
    uint64_t a, b, c;
    int cnt_w = 0;
    int Try = 1e6;
    while (Try--) {
        a = (uint64_t) ra() % limit + 1;
        b = (uint64_t) ra() % limit + 1;
        c = (uint64_t) ra() % limit + 1;
        uint64_t m1, m2;
        m1 = mul5(a,b,c);
        m2 = mul6(a,b,c);
        if (m1!=m2) {
            cnt_w++;
        }
    }
    cout << cnt_w;
    return 0;
}
