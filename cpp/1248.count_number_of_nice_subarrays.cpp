class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int countOdd = 0;
        int result = 0;
        int currentSubarrayCount = 0;
        while (right < nums.size()) {
            if (nums[right] % 2) {
                countOdd++;
                currentSubarrayCount = 0;
            }
            while (countOdd == k) {
                currentSubarrayCount++;
                if (nums[left] % 2) {
                    countOdd--;
                }
                left++;
            }
            result += currentSubarrayCount;
            right++;
        }
        return result;
    }
};


