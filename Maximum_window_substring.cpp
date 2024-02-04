class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> targetFreq;
    for (char ch : t) {
        targetFreq[ch]++;
    }

    int requiredChars = targetFreq.size();
    int left = 0, right = 0, formed = 0;
    unordered_map<char, int> windowFreq;

    int minLen = INT_MAX;
    string result = "";

    while (right < s.length()) {
        char currentChar = s[right];
        windowFreq[currentChar]++;

        if (targetFreq.find(currentChar) != targetFreq.end() &&
            windowFreq[currentChar] == targetFreq[currentChar]) {
            formed++;
        }
        while (formed == requiredChars) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                result = s.substr(left, minLen);
            }
            char leftChar = s[left];
            windowFreq[leftChar]--;

            if (targetFreq.find(leftChar) != targetFreq.end() &&
                windowFreq[leftChar] < targetFreq[leftChar]) {
                formed--;
            }

            left++;
        }

        right++;
    }

    return result;
    }
};