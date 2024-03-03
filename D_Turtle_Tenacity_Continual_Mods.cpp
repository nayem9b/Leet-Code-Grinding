#include <iostream>
#include <unordered_map>

using namespace std;

bool isPossible(int arr[], int n) {
  // Count the frequency of each remainder after dividing by 10
  unordered_map<int, int> remainder_count;
  for (int i = 0; i < n; ++i) {
    remainder_count[arr[i] % 10]++;
  }

  // Check conditions based on remainder counts:
  // 1. The first element (i.e., b1) cannot be 0.
  if (remainder_count[0] > 0) return false;

  // 2. For every remainder r (except 0), the count of r+1 must be greater than or equal to the count of r.
  // This ensures that we can always find a subsequent element with a larger remainder.
  for (int r = 1; r <= 9; ++r) {
    if (remainder_count[r] < remainder_count[r - 1]) {
      return false;
    }
  }

  // If all conditions are met, it's possible to rearrange the array.
  return true;
}

int main() {
  int t, n;

  cin >> t;
  while (t--) {
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    if (isPossible(arr, n)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
