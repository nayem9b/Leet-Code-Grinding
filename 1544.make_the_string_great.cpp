class Solution {
public:
    string makeGood(string s) {
        string result = "";
        stack<char> Stack;

        for (char ch : s) {
            if (!Stack.empty() && abs(Stack.top() - ch) == 32) {
                Stack.pop();
            } else {
                Stack.push(ch);
            }
        }

        while (!Stack.empty()) {
            result = Stack.top() + result;
            Stack.pop();
        }

        return result;
    }
};
