class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int allXOR =0;

        //XOR all numbers in range [0,n]
        for (int i = 0; i <=nums.size(); i++)
        {
            allXOR = allXOR^i;
        }

        //XOR all numbers in the given array
        for (int num:nums)
        {
            allXOR = allXOR^num;
        }
        
        //return the missing number
        return allXOR;
    }
};