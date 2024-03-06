class Solution {
public:
    int rob(vector<int>& nums) {
        // If only 1 element, just return it
        if (nums.size() < 2)
            return nums[0];

        // Create vector to store the maximum loot at each index
        vector<int> dp(nums.size());

        // Memoize maximum loots at first 2 indexes
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        // Use them to fill complete array
        for (int i = 2; i < nums.size(); i++) {
            // Core logic
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[nums.size() - 1];
    }
};
