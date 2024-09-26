#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        int sum = 0;
        int left=0, right=n-1;
        while(left<right){
            sum += a[right] - a[left];
            left++;
            right--;
        }
        cout << sum << endl;
       
    }
    return 0;
}