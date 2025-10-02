#include <bits/stdc++.h>
using namespace std;

long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    if (r > n - r) r = n - r;
    long long res = 1;
    for (int i = 1; i <= r; ++i) {
        res = res * (n - r + i) / i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s1, s2;
    if (! (cin >> s1 >> s2)) return 0;
    
    int target = 0;
    for (char c : s1) target += (c == '+') ? 1 : -1;
    
    int cur = 0, k = 0;
    for (char c : s2) {
        if (c == '+') cur += 1;
        else if (c == '-') cur -= 1;
        else if (c == '?') ++k;
    }
    
    int diff = target - cur;
    long double prob = 0.0L;
    
    if (k == 0) {
        prob = (diff == 0) ? 1.0L : 0.0L;
    } else {
        if ( (k + diff) % 2 == 0 ) {
            int x = (k + diff) / 2;
            if (0 <= x && x <= k) {
                long long ways = nCr(k, x);
                long long total = 1LL << k; 
                prob = (long double)ways / (long double)total;
            }
        }
    }
    
    cout.setf(std::ios::fixed); 
    cout << setprecision(12) << (double)prob << '\n';
    return 0;
}
