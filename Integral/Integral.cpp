#include <bits/stdc++.h>

using namespace std;

namespace cach1 {
    const int STEP = 1e6;
    double f(double x) {
        /* function here */
    }
    double integral(double x1, double x2) {
        double d = (x2-x1)/STEP;
        double S = 0;
        for (int i = 0; i < STEP; ++i) {
            S += (f(x1+i*d)+f(x1+(i+1)*d))*d/2;
        }
        return S;
    }
    double integral2(double x1, double x2) {
        double d = (x2-x1)/STEP;
        double S = f(x1) + f(x2);
        for (int i = 1; i < STEP; ++i) {
            S += 2*f(x1+i*d);
        }
        return S*d/2;
    }
}

namespace cach2 { // Simpson's rule
    const int STEP = 1e6;
    double f(double x) {
        /* function here */
    }
    double integral(double x1, double x2) {
        double d = (x2-x1)/STEP;
        double S = f(x1) + f(x2);
        for (int i = 1; i < STEP; ++i) {
            S += f(x1+i*d) * (i&1?4:2);
        }
        return S*d/3;
    }
}

namespace cach3 { // simpson fomula 2
    const double eps = 1e-12;
    double f(double x) {
        /* function here */
    }
    double simpson(double x1, double x2) {
        return (x2-x1)/6*(f(x1)+f(x2)+4*f((x1+x2)/2));
    }
    double integral(double x1, double x2, double ans) {
        double m = (x1+x2)/2;
        double lef = simpson(x1,m);
        double rig = simpson(m,x2);
        if (fabs(lef+rig-ans) < eps) return ans;
        return integral(x1,m,lef) + integral(m,x2,rig);
    }
    double integral(double x1, double x2) {
        return integral(x1,x2,simpson(x1,x2));
    }
}

int main() {
    double x1, x2;
    cin >> x1 >> x2;
    cout << cach1::integral(x1,x2);
    cout << cach1::integral2(x1,x2);
    cout << cach2::integral(x1,x2);
    cout << cach3::integral(x1,x2);
    return 0;
}
