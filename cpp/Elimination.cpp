#include <bits/stdc++.h>
using namespace std;
bool isEliminated(const string &str)
{
    stack<char> s;
    for (char c : str)
    {
        if (c == '1')
        {
            if (!s.empty() && s.top() == '0')
            {
                s.pop();
            }
            else
            {
                s.push(c);
            }
        }
        else
        {
            s.push(c);
        }
    }
    return s.empty();
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        if (isEliminated(str))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
    return 0;
}