#include <vector>
#include <algorithm>

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        // Sort the people by weight
        sort(people.begin(), people.end());

        int boats = 0;

        // Use 2 pointers to find the heaviest and lightest person
        int left = 0, right = people.size() - 1;

        while (left <= right) {
            // If heaviest and lightest person can fit in the same boat
            if (people[left] + people[right] <= limit) {
                left++;
            }

            // In any case, the heaviest person will be on the boat
            right--;

            // Increment the number of boats
            boats++;
        }

        return boats;
    }
};
