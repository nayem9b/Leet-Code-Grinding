#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int a = 0;
        int b = 0;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    a = i;
                    b = j;
                }
            }
        }
        return {a, b};
    }
};
<<<<<<< HEAD
// int main()
// {
//    Solution First(2,7,11,15); 
// }
=======
>>>>>>> 18107664fb6687ce6d85689f74cbdd7d553baea0
