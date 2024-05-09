#include <bits/stdc++.h>
using namespace std;

void print_left_to_right(list<int> queries)
{
    cout << "L -> ";
    if (queries.empty())
    {
        cout << endl;
        return;
    }
    for (int v : queries)
    {
        cout << v << " ";
    }
    cout << endl;
}

void print_right_to_left(list<int> queries)
{
    cout << "R -> ";
    if (queries.empty())
    {
        cout << endl;
        return;
    }
    list<int> copy_queries(queries);
    copy_queries.reverse();
    for (int v : copy_queries)
    {
        cout << v << " ";
    }
    cout << endl;
}

int main()
{

    list<int> queries;
    int n;
    cin >> n;
    while (n--)
    {
        int x, v;
        cin >> x >> v;
        if (x == 0)
        {
            queries.push_front(v);
        }
        else if (x == 1)
        {
            queries.push_back(v);
        }
        else
        {
            int size = queries.size();
            if (v < size)
            {
                queries.erase(next(queries.begin(), v));
            }
        }
        print_left_to_right(queries);
        print_right_to_left(queries);
    }
    return 0;
}