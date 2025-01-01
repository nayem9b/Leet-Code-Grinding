#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    return 0;
}

// class Solution:
//     def pickGifts(self, gifts: List[int], k: int) -> int:

//         gifts = [ -g for g in gifts] #list comprehension. Turns each value to -1 and make a list
//         heapq.heapify(gifts)

//         for _ in range(k):
//            n = -heapq.heappop(gifts)

//            heapq.heappush(gifts, -floor(sqrt(n)))

//         return -sum(gifts)
      

#include <vector>
#include <queue>
#include <cmath>
#include <numeric> // For accumulate

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Create a min-heap with negative values to mimic a max-heap
        priority_queue<int> pq;
        for (int gift : gifts) {
            pq.push(-gift); // Push negative values
        }

        // Perform k operations
        for (int i = 0; i < k; ++i) {
            int n = -pq.top(); // Get the largest value (convert back to positive)
            pq.pop();
            pq.push(-static_cast<int>(floor(sqrt(n)))); // Push modified value as negative
        }

        // Calculate the sum of the remaining elements
        long long sum = 0;
        while (!pq.empty()) {
            sum -= pq.top(); // Convert back to positive while summing
            pq.pop();
        }

        return sum;
    }
};
