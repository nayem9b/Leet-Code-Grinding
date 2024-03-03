#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        int sum = 0;

        // Input array elements and calculate sum
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i];
        }

        // Calculate the remainder when the sum is divided by 3
        int remainder = sum % 3;

        // Count the number of elements with remainders 1 and 2
        int count1 = 0, count2 = 0;
        for (int i = 0; i < n; ++i) {
            if (arr[i] % 3 == 1) count1++;
            if (arr[i] % 3 == 2) count2++;
        }

        // Calculate the minimum number of moves required
        int moves = 0;
        if (remainder == 1) {
            // If remainder is 1, we need to either remove one element with remainder 1
            // or remove two elements with remainder 2
            if (count1 >= 1) moves = 1;
            else if (count2 >= 2) moves = 2;
            else moves = -1; // Impossible case
        } else if (remainder == 2) {
           moves = 1;
        }

        // Print the minimum number of moves required
        cout << moves << endl;
    }

    return 0;
}
