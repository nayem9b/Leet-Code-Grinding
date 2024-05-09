#include <iostream>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, l;
        cin >> a >> b >> l;

        int count = 0;
        for (int k = 0; k <= l; ++k) {
            for (int x = 0; k * pow(a, x) <= l; ++x) {
                for (int y = 0; k * pow(a, x) * pow(b, y) <= l; ++y) {
                    if (k * pow(a, x) * pow(b, y) == l) {
                        count++;
                    }
                }
            }
        }

        cout << count << endl;
    }

    return 0;
}
