class Solution {
public:
    // time/space: O(n)/O(1)
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int result = 0;
        long long product = 1LL;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            // update the product of `nums[l..r]`
            product *= nums[r];
            // shrink the window if the product is too large
            while ((l < r) && (product >= k)) product /= nums[l++];
            // update the result if the current product meets the condition
            if (product < k) result += (r - l + 1);
        }
        return result;
    }
};