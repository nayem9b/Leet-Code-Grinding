class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        unordered_set<int> intersect;
        vector<int> result;

        for (int num : nums2) {
            if (set.count(num)) {
                intersect.insert(num);
            }
        }

        for (int num : intersect) {
            result.push_back(num);
        }

        return result;
    }
};