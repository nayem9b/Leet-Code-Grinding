class Solution {
public:
    bool isPalindrome(const string& s) {
        int i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (const string& word : words) {
            stringstream ss(word);
            string temp;
            while (ss >> temp) {
                if (isPalindrome(temp)) {
                    return temp;
                }
            }
        }
        return "";
    }
};