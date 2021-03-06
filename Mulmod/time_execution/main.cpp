#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

static uint64_t mul(uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r = 0;
    if (a >= m) a %= m;   /* Careful attention from the caller */
    if (b >= m) b %= m;   /* should make these unnecessary.    */
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

static uint64_t mul4(uint64_t a, uint64_t b, uint64_t m) {
    if (a>=m) a %= m;
    if (b>=m) b %= m;
    if ((a|b) < (1ULL << 32)) return (a*b) % m;
    if (a < b) { uint64_t t = a; a = b; b = t; }
    int stepSize = __builtin_clz((uint32_t)(m>>32));
    if (stepSize == 0) return slowModulo(a,b,m);
    return fastModulo(a,b,m,stepSize);
}

uint64_t mul5(uint64_t a, uint64_t b, uint64_t m) {
    auto res = (unsigned __int128) a * b % m;
    return (uint64_t) res;
}

uint64_t mul6(uint64_t a, uint64_t b, uint64_t m) {
    if (a >= m) a %= m;
    if (b >= m) b %= m;
    uint64_t q = (long double) a * b / m;
    uint64_t r = a * b - q * m;
    return r;
}

const int MI = 1000;
const int MA = 1e7;
const int TRY = 5;
const int NTEST = 4;
struct _test_ {
    uint64_t a, b, m;
} t[NTEST];

void init() {
    t[0].m = (1ull<<32)-1;
    t[0].a = t[0].m - 123;
    t[0].b = t[0].m - 456;

    t[1].m = (1ull<<50) - 9325;
    t[1].a = t[1].m - 123;
    t[1].b = t[1].m - 456;

    t[2].m = 1ull<<63;
    t[2].a = t[2].m - 123;
    t[2].b = t[2].m - 456;

    t[3].m = (1ull<<63) + ((1ull<<63)-1);
    t[3].a = t[3].m - 123;
    t[3].b = t[3].m - 456;
}

double process(int time, uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r;
    auto start = high_resolution_clock::now();
    while (time--) {
        r = mul(a,b,m);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}

double process_1(int time, uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r;
    auto start = high_resolution_clock::now();
    while (time--) {
        r = mul1(a,b,m);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}

double process_2(int time, uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r;
    auto start = high_resolution_clock::now();
    while (time--) {
        r = mul2(a,b,m);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}

double process_3(int time, uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r;
    auto start = high_resolution_clock::now();
    while (time--) {
        r = mul3(a,b,m);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}

double process_4(int time, uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r;
    auto start = high_resolution_clock::now();
    while (time--) {
        r = mul4(a,b,m);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}

double process_5(int time, uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r;
    auto start = high_resolution_clock::now();
    while (time--) {
        r = mul5(a,b,m);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}

double process_6(int time, uint64_t a, uint64_t b, uint64_t m) {
    uint64_t r;
    auto start = high_resolution_clock::now();
    while (time--) {
        r = mul6(a,b,m);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    return duration.count() / 1000000.0;
}

int main() {
    freopen("result.txt", "w", stdout);

    init();

    for (int it = 0; it < NTEST; ++it) {
        cout << "TEST: " << it << '\n';
        cerr << "TEST: " << it << '\n';
        uint64_t a = t[it].a;
        uint64_t b = t[it].b;
        uint64_t m = t[it].m;
        for (int time = MI; time <= MA; time*=10) {
            cout << "- Time: " << time << '\n';
            cerr << "- Time: " << time << '\n';
            double p[7] = {0};
            for (int Try = 1; Try <= TRY; ++Try) {
                p[0] += process(time, a, b, m);
                p[1] += process_1(time, a, b, m);
                p[2] += process_2(time, a, b, m);
                if (it<NTEST-1) p[3] += process_3(time, a, b, m);
                else p[3] = -TRY;
                p[4] += process_4(time, a, b, m);
                p[5] += process_5(time, a, b, m);
                p[6] += process_6(time, a, b, m);
            }
            for (int i = 0 ; i <= 6; ++i) {
                cout << "---> mul" << i << ": " << p[i]/TRY << '\n';
                cerr << "---> mul" << i << ": " << p[i]/TRY << '\n';
            }
        }
        cout << '\n';
        cerr << '\n';
    }
    return 0;
} 
