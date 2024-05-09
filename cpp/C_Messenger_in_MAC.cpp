#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maximumSetSize(int n, int l, vector<pair<int, int>>& messages) {
    sort(messages.begin(), messages.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    vector<vector<int>> dp(n + 1, vector<int>(l + 1, 0));

    for (int i = 1; i <= n; ++i) {
        int a = messages[i - 1].first;
        int b = messages[i - 1].second;

        for (int j = 0; j <= l; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);

            if (j >= b) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - b] + a);
            }
        }
    }

    return dp[n][l];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, l;
        cin >> n >> l;

        vector<pair<int, int>> messages(n);
        for (int i = 0; i < n; ++i) {
            cin >> messages[i].first >> messages[i].second;
        }

        cout << maximumSetSize(n, l, messages) << endl;
    }

    return 0;
}
