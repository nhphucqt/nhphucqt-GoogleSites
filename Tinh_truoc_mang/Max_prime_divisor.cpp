#include <bits/stdc++.h>
 
using namespace std;
 
const int nmax = 1000007;
int n, max_d[2*nmax];
 
int phantich(int k) // tim uoc nguyen to lon nhat nho vao phan tich thanh thua so nguyen to
{
    while (max_d[k] != k) k /= max_d[k];
    return k;
}
 
void max_divisor()
{
    for(int i = 2; i <= nmax; ++i) max_d[i] = i; 
    for (int i = 2; i*i <= nmax; ++i) // tinh truoc uoc nguyen to nho nhat
    {
        if (max_d[i] == i)
        {
            for (int j = i; j <= nmax/i; ++j)
                if (max_d[i*j] == i*j) max_d[i*j] = i;
        }
    }
    for (int i = nmax; i >= 2; --i) // tinh truoc uoc nguyen to lon nhat
    {
        max_d[i] = phantich(i);
    }
}
 
int main()
{
    max_divisor();
    cin >> n;
    cout << max_d[n];
    return 0;
}
