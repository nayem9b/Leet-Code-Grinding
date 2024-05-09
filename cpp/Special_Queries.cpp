#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    cin >> q;

    queue<string> line;

    while (q--)
    {
        int command;
        cin >> command;

        if (command == 0)
        {
            string name;
            cin >> name;
            line.push(name);
        }
        else if (command == 1)
        {
            if (!line.empty())
            {
                cout << line.front() << endl;
                line.pop();
            }
            else
            {
                cout << "Invalid" << endl;
            }
        }
    }

    return 0;
}
