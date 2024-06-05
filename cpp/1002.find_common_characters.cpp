class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        array<char, 26> freq, minFreq;
        minFreq.fill(100);
        for(auto& w: words){
            freq.fill(0);
            for(char c: w) freq[c-'a']++;
            for(int i=0; i<26; i++)
                minFreq[i]=min(freq[i], minFreq[i]);
        }
        int sz=accumulate(minFreq.begin(), minFreq.end(), 0);
        vector<string> ans;
        ans.reserve(sz);
        for(int i=0; i<26; i++){         
            ans.insert(ans.end(), minFreq[i], string(1, 'a'+i));
        }
        return ans;
    }
};


