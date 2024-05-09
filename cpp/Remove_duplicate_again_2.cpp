#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(list<int> &myList)
{
    myList.sort();
    myList.unique();
}

int main()
{
    list<int> myList;
    int value;
    while (cin >> value && value != -1)
    {
        myList.push_back(value);
    }
    removeDuplicates(myList);
    for (const auto &val : myList)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}