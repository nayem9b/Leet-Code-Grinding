#include <bits/stdc++.h>
using namespace std;
bool isValid(const string& str)
{
    stack<char> s;
    for (char c : str)
    {
        if (c == '0')
        {
            if (!s.empty() && s.top() == '1')
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
            if (!s.empty() && s.top() == '0')
            {
                s.pop();
            }
            else
            {
                s.push(c);
            }
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
        if (isValid(str))
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