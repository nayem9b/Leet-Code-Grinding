class Solution {
public:
    string makeGood(string s) {
        string result = "";
        stack<char> charStack;

        for (char ch : s) {
            if (!charStack.empty() && abs(charStack.top() - ch) == 32) {
                charStack.pop();
            } else {
                charStack.push(ch);
            }
        }

        while (!charStack.empty()) {
            result = charStack.top() + result;
            charStack.pop();
        }

        return result;
    }
};
