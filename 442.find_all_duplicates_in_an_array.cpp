class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> resultSet;

        for (int i = 0; i < nums.size(); ++i) {
            // Get the index the element corresponds to
            int index = abs(nums[i]) - 1;

            // If the number is already negative, it means we are encountering it twice
            if (nums[index] < 0)
                resultSet.push_back(index + 1);

            // Flip the number at the index to negative
            nums[index] *= -1;
        }

        return resultSet;
    }
};