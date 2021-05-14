#include <bits/stdc++.h>

using namespace std;

const double eps = 1e-12;
const double PI = acos(-1);
int n;

struct Func {
    int deg;
    vector<double> a;
    void init(int n) {
        deg = n;
        a.resize(n+1);
    }
    friend istream& operator >> (istream&is,Func&f) {
        for (int i = 0; i <= f.deg; ++i) {
            is >> f.a[i];
        } return is;
    }
    double eval(double x) {
        double res = 0;
        for (int i = 0; i <= deg; ++i) {
            res += a[i]*pow(x,i);
        } return res;
    }
} func;

double f(double x) {
    double res = func.eval(x);
    return res*res;
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

double BinSearch(double lef, double rig, double inc) {
    double rt = lef;
    int step = 100;
    for (int i = 0; i < step; ++i) {
        double mid = (lef+rig)/2;
        if (integral(rt,mid,simpson(rt,mid))*PI < inc) {
            lef = mid;
        } else rig = mid;
    } 
    return lef;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    int Case = 0;
    cout << setprecision(2) << fixed;
    while (cin >> n) {
        Case++;
        func.init(n);
        cin >> func;
        int inc;
        double xlow, xhigh;
        cin >> xlow >> xhigh >> inc;
        double volume = integral(xlow,xhigh,simpson(xlow,xhigh))*PI;
        cout << "Case " << Case << ": " << volume << '\n';
        if (volume < inc) cout << "insufficient volume\n";
        else {
            double p = xlow;
            for (int i = 1; i <= 8 && integral(p,xhigh,simpson(p,xhigh))*PI >= inc; ++i) {
                p = BinSearch(p,xhigh,inc);
                cout << p-xlow << ' ';
            } cout << '\n';
        }
    }
    
    return 0;
}
