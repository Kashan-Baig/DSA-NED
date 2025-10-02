#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long a, b;
    if (!(cin >> a >> b)) return 0;

    vector<long long> seq;
    long long cur = b;
    seq.push_back(cur);

    while (cur > a) {
        if (cur % 10 == 1) {
            cur = (cur - 1) / 10;
            seq.push_back(cur);
        } else if (cur % 2 == 0) {
            cur = cur / 2;
            seq.push_back(cur);
        } else {
            break;
        }
    }

    if (cur != a) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        reverse(seq.begin(), seq.end()); // now from a to b
        cout << seq.size() << "\n";
        for (size_t i = 0; i < seq.size(); ++i) {
            if (i) cout << ' ';
            cout << seq[i];
        }
        cout << "\n";
    }

    return 0;
}