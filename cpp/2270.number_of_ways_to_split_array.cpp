#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    return 0;
}


class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();
        long long sum=0;
        long long psum=0;
        int count=0;
        for(int num: nums)
        {
            sum += num;
        }
        
        for (int i = 0; i < n-1; i++)
        {
            psum+= nums[i];
            if(psum>=sum-psum)
            {
                count++;
            }
        }
        
        return count;

    }
};