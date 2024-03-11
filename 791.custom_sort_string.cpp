class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> counts;
        for (char c : s)
            counts[c]++;
        
        string output;
        for (char c : order) {
            if (counts.find(c) != counts.end()) {
                output.append(counts[c], c);
                counts.erase(c);
            }
        }
        
        for (auto& pair : counts) {
            output.append(pair.second, pair.first);
        }
        
        return output;
    }
};