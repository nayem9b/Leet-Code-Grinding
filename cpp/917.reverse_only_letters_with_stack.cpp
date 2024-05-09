class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> letters;
        
        // Push letters onto the stack
        for(char c : s) {
            if(isalpha(c)) {
                letters.push(c);
            }
        }
        
        // Replace letters in the string
        for(char& c : s) {
            if(isalpha(c)) {
                c = letters.top();
                letters.pop();
            }
        }
        
        return s;
    }
};