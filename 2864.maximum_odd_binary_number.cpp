class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n = s.length();
        string ans="1";
        int countOnes = count(s.begin(),s.end(), '1');
        int zeros = n-countOnes;
        while(zeros--){
            ans+="0";
        }
        countOnes --;

        while(countOnes--){
            ans+="1";
        }
        reverse(ans.begin(), ams.end());
        return ans;
    }
};