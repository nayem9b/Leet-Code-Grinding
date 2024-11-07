#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
     int largestCombination(vector<int> & candidates){
        int max_freq=0;

        for (int i = 0; i < 32; i++)
        {   
            int freq=0;
            for (int candidate : candidates)
            {
                if(candidate & (1<<i))
                freq++;
            }
           max_freq=max(max_freq, freq); 
        }
        return max_freq;
        
     }
};

int main()
{
    
    return 0;
}