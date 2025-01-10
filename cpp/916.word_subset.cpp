#include <bits/stdc++.h>
using namespace std;

vector<string> findStringsWithChars(
    const vector<string> &words1,
    const unordered_map<char, int> &charFrequency)
{
    vector<string> result;

    for (const string &word : words1)
    {
        unordered_map<char, int> charsInWord;
        for (char c : word)
        {
            charsInWord[c]++;
        }

        bool containsAll = true;
        for (const auto &entry : charFrequency)
        {
            if (charsInWord[entry.first] < entry.second)
            {
                containsAll = false;
                break;
            }
        }

        if (containsAll)
        {
            result.push_back(word);
        }
    }

    return result;
}

class Solution
{
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2)
    {
        unordered_map<char, int> charFrequency;
        for (const string &word : words2)
        {
            unordered_map<char, int> tempFreq;
            for (char c : word)
            {
                tempFreq[c]++;
            }

            for (const auto &entry : tempFreq)
            {
                charFrequency[entry.first] = max(charFrequency[entry.first], entry.second);
            }
        }

        return findStringsWithChars(words1, charFrequency);
    }
};