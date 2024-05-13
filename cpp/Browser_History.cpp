#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    string val;
    ListNode *prev;
    ListNode *next;
    ListNode(string x) : val(x), prev(nullptr), next(nullptr) {}
};

class WebBrowser
{
private:
    ListNode *head;
    ListNode *curr;

public:
    WebBrowser() : head(nullptr), curr(nullptr) {}

    void visit(const string &address)
    {
        ListNode *temp = findAddress(address);
        if (!temp)
        {
            cout << "Not Available" << endl;
        }
        else
        {
            curr = temp;
            cout << curr->val << endl;
        }
    }
    void next()
    {
        if (curr && curr->next)
        {
            curr = curr->next;
            cout << curr->val << endl;
        }
        else
        {
            cout << "Not Available" << endl;
        }
    }
    void prev()
    {
        if (curr && curr->prev)
        {
            curr = curr->prev;
            cout << curr->val << endl;
        }
        else
        {
            cout << "Not Available" << endl;
        }
    }

    void addAddress(const string &address)
    {
        ListNode *newNode = new ListNode(address);
        if (!head)
        {
            head = curr = newNode;
        }
        else
        {
            curr->next = newNode;
            newNode->prev = curr;
            curr = newNode;
        }
    }

private:
    ListNode *findAddress(const string &address)
    {
        ListNode *temp = head;
        while (temp)
        {
            if (temp->val == address)
                return temp;
            temp = temp->next;
        }
        return nullptr;
    }
};

int main()
{
    WebBrowser browser;
    string address;

    while (cin >> address && address != "end")
    {
        browser.addAddress(address);
    }
    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        string command;
        cin >> command;
        if (command == "visit")
        {
            cin >> address;
            browser.visit(address);
        }
        else if (command == "next")
        {
            browser.next();
        }
        else if (command == "prev")
        {
            browser.prev();
        }
    }

    return 0;
}
