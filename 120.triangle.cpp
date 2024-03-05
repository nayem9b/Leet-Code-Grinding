class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        vector<vector<int>> dp(height + 1, vector<int>(height + 1));
        for (int level = height - 1; level >= 0; level--) {
            for (int i = 0; i <= level; i++) {
                dp[level][i] = triangle[level][i]
                    + min(dp[level + 1][i], dp[level + 1][i + 1]);
            }
        }
        return dp[0][0];
    }
};