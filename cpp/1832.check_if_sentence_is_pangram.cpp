class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> alphabetSet;

        // Add all characters from 'a' to 'z' in unordered_set
        for (char c = 'a'; c <= 'z'; c++) {
            alphabetSet.insert(c);
        }

        // Remove every character and check
        // if set becomes empty at any point of time
        for (int i = 0; i < sentence.length(); i++) {
            alphabetSet.erase(sentence[i]);
            if (alphabetSet.empty())
                return true;
        }

        return false;
    }
};