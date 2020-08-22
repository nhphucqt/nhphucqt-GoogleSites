#include <bits/stdc++.h>

using namespace std;

// m < 2^64, có cộng tràn số, tối ưu, code dài, phức tạp
static uint64_t mul(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r = 0;
    if (a >= m) a %= m;
    if (b >= m) b %= m;
    if ((a|b) < (1ull << 32)) return (a*b) % m;
    if (a < b) { uint64_t t = a; a = b; b = t; }
    if (m <= (1ull << 63)) {
        while (b > 0) {
            if (b & 1) { r += a;  if (r >= m) r -= m; }
            b >>= 1;
            if (b) { a += a;  if (a >= m) a -= m; }
        }
    } else {
        while (b > 0) {
            if (b & 1) r = ((m-r) > a) ? r+a : r+a-m;    /* r = (r + a) % n */
            b >>= 1;
            if (b) a = ((m-a) > a) ? a+a : a+a-m;    /* a = (a + a) % n */
        }
    }
    return r;
}

// m < 2^64, có cộng tràn số, đơn giản hơn mul
uint64_t mul1(uint64_t a, uint64_t b, uint64_t m) {
    a %= m;
    b %= m;
    if ((a|b)<(1ull<<32)) return a*b%m;
    uint64_t res = 0;
    while (b>0) {
        if (b&1) res = (m-res>a) ? res+a : res+a-m;
        a = (m-a>a) ? a<<1 : (a<<1)-m;
        b >>= 1;
    }
    return res;
}

// m < 2^64, không có cộng tràn số, đơn giản hơn mul
uint64_t mul2(uint64_t a, uint64_t b, uint64_t m) {
    a %= m;
    b %= m;
    if ((a|b)<(1ull<<32)) return a*b%m;
    uint64_t res = 0;
    while (b>0) {
        if (b&1) res = (m-res>a) ? res+a : res-(m-a);
        a = (m-a>a) ? a<<1 : a-(m-a);
        b >>= 1;
    }
    return res;
}

// m <= 2^63, đơn giản, chậm
uint64_t mul3(uint64_t a, uint64_t b, uint64_t m) {
    a %= m; b %= m;
    uint64_t res = 0;
    for (; b>0; a=(a<<1)%m,b>>=1) {
        if (b&1) res = (res+a)%m;
    }
    return res;
}

static uint64_t slowModulo(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r = 0;
    uint64_t C_down = m>>1;
    uint64_t C_up = m - C_down;
    while (b > 0) {
        if (b&1) r = ((r >= m - a) ? (a >= C_up ? a - C_up + r : r - C_up + a) - C_down : r+a);
        if (a >= C_up) a = (a-C_down)+(a-C_up);
        else a = a+a;
        b >>= 1;
    }
    return r;
}

// stepSize càng lớn thì chạy càng nhanh
static uint64_t fastModulo(uint64_t a, uint64_t b, uint64_t m, uint64_t stepSize) {
    uint64_t mask = (1 << stepSize) - 1;
    uint64_t r = 0;
    while (b > 0) {
        r += a * (b&mask); r %= m;
        a <<= stepSize; a %= m;
        b >>= stepSize;
    }
    return r;
}

// m < 2^64, code dài, phức tạp
static uint64_t mul4(uint64_t a, uint64_t b, uint64_t m) {
    if (a>=m) a %= m;
    if (b>=m) b %= m;
    if ((a|b) < (1ULL << 32)) return (a*b) % m;
    if (a < b) { uint64_t t = a; a = b; b = t; }
    int stepSize = __builtin_clz((uint32_t)(m>>32));
    if (stepSize == 0) return slowModulo(a,b,m);
    return fastModulo(a,b,m,stepSize);
}

// m < 2^64, nhanh, một số bộ dịch không hỗ trợ
uint64_t mul5(uint64_t a, uint64_t b, uint64_t m) {
    auto res = (unsigned __int128) a * b % m;
    return (uint64_t) res;
}

// m < 2^64, nhanh hơn mul5, nhưng có thể bị sai số vì dùng số thực
uint64_t mul6(uint64_t a, uint64_t b, uint64_t m) {
    if (a >= m) a %= m;
    if (b >= m) b %= m;
    uint64_t q = (long double) a * b / m;
    uint64_t r = a * b - q * m;
    return r;
}
