#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("omit-frame-pointer")
#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

const int TIME = 1e3;
long long sum;
double aver;
int mins = 1e9, maxs;

int main()
{
    int time = TIME;
    while (time--) {
        system("count.exe");
        int cnt;
        ifstream inp("output.txt");
        inp >> cnt;
        inp.close();
        sum += cnt;
        mins = min(mins, cnt);
        maxs = max(maxs, cnt);
    }
    aver = 1.0*sum/TIME;
    ofstream out("result.txt");
    out << "- Time    : " << TIME << '\n';
    out << "- Total   : " << sum << '\n';
    out << "- Average : " << setprecision(3) << fixed << aver << '\n';
    out << "- Min     : " << mins << '\n';
    out << "- Max     : " << maxs << '\n';
    out.close();
    return 0;
}
