class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> result(nums.size());

        // Square all elements
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = nums[i] * nums[i];
        }

        int head = 0;
        int tail = nums.size() - 1;

        // Set them at the right place in the result array
        for (int pos = nums.size() - 1; pos >= 0; pos--) {
            if (nums[head] > nums[tail]) {
                result[pos] = nums[head];
                // Increment head pointer
                head++;
            } else {
                result[pos] = nums[tail];
                // Decrement tail pointer
                tail--;
            }
        }

        return result;
    }
};