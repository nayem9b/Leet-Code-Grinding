#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    stack<int> s;
    queue<int> q;
    while (n--)
    {
        int value;
        cin >> value;
        s.push(value);
    }
    while (m--)
    {
        int value;
        cin >> value;
        q.push(value);
    }
    while (!s.empty() && !q.empty())
    {
        if (s.top() == q.front())
        {
            s.pop();
            q.pop();
        }
        else
        {
            break;
        }
    }
    if (s.empty() && q.empty())
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}