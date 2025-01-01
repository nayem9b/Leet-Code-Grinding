class Solution {
public:
    int maxScore(string s) {
        int zero=0, one =0, res=0;

        for (char c : s) {
            if (c == '1') one++;
        }

        for(int i=0; i<s.size()-1; i++){
            if(s[i]=='0') zero++;
            else one--;
            res = max(res, zero+one);
        }
        return res;
    }
};