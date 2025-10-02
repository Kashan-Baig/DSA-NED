#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());

    vector<string> results;
    do {
        results.push_back(s);
    } while (next_permutation(s.begin(), s.end()));

    cout << results.size() << "\n";
    for (auto &str : results) {
        cout << str << "\n";
    }

    return 0;
}
