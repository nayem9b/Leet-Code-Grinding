#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int maxVowels(string s, int k) {
        int maxVowels = 0;
        int windowVowels = 0;

        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        // Count the number of vowels in the first window
        for (int i = 0; i < k; i++)
            if (vowels.find(s[i]) != vowels.end())
                windowVowels++;

        maxVowels = windowVowels;

        // Slide the window and update the maximum number of vowels
        for (int i = k; i < s.length(); i++) {
            if (vowels.find(s[i - k]) != vowels.end())
                windowVowels--;

            if (vowels.find(s[i]) != vowels.end())
                windowVowels++;

            maxVowels = max(maxVowels, windowVowels);
        }

        return maxVowels;
    }
};
