#include <iostream>
#include <algorithm>

string smallestString(int n, string s)
{
    string result;

   if (n % 2 == 0)
    {
         std::reverse(s.begin(), s.end());
    }

    result = s;

    for (int i = 1; i < n; i++)
    {
        result += s;
    }

    return result;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        string s;
        cin >> n >>s;
        cout << smallestString(n, s) << endl;
    }

    return 0;
}
