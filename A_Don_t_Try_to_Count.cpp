#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;

    for (int i = 0; i < 6; ++i) {
        if (x.find(s) != string::npos) {  
            cout << i << endl;
            return;
        }
        x += x;
    }

    cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
