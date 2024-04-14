#include <bits/stdc++.h>
using namespace std;
class myStack
{
public:
    vector<int> v;
    void push(int val)
    {
        v.push_back(val);
    }
    void pop()
    {
        v.pop_back();
    }
    int top()
    {
        return v.back();
    }
    int size()
    {
        return v.size();
    }
    bool empty()
    {
        if (v.size() == 0)
            return true;
        else
            return false;
    }
};
class myQueue
{
public:
    list<int>l;
    int sz = 0;
    void push(int val)
    {
      l.push_back(val);
    }
    void pop()
    {
        l.pop_front();
    }
    int front()
    {
        return l.front();
    }
    int size()
    {
        return l.size();
    }
    bool empty()
    {
       return l.empty();
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    myStack s;
    myQueue q;
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