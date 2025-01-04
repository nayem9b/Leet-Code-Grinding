#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int minOper = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t == 0)
        {
            minOper = 0;
            break;
        }
        minOper = min(minOper, abs(t));
    }
    cout << minOper << endl;
}

int main()
{
    int T = 1;
    while (T--) 
    {
        solve();
    }
}