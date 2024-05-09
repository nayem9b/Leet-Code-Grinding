#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void printNormal(Node *head)
{
    Node *tmp = head;
    cout << "L"
         << " "
         << "->"
         << " ";
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

void printReverse(Node *tail)
{
    Node *tmp = tail;
    cout << "R"
         << " "
         << "->"
         << " ";
    while (tmp != nullptr)
    {
        cout << tmp->val << " ";
        if (tmp->prev != nullptr)
        {
            tmp = tmp->prev;
        }
        else
        {
            break;
        }
    }
    cout << endl;
}

void insertAtPosition(Node *head, int pos, int val)
{
    Node *newNode = new Node(val);
    Node *tmp = head;
    for (int i = 1; i <= pos - 1; i++)
    {
        tmp = tmp->next;
    }
    newNode->next = tmp->next;
    tmp->next = newNode;

    newNode->next->prev = newNode;
    newNode->prev = tmp;
}

void insertAtHead(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertTail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);

    if (tail == nullptr)
    {
        tail = newNode;
        head = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = tail->next;
}

int size(Node *head)
{
    Node *tmp = head;
    int cnt = 0;
    while (tmp != nullptr)
    {
        cnt++;
        tmp = tmp->next;
    }
    return cnt;
}
int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    int tt;
    cin >> tt;
    while (tt--)
    {
        int pos, val;
        cin >> pos >> val;
        if (pos == 0)
        {
            insertAtHead(head, tail, val);
        }
        else if (pos == size(head))
        {
            insertTail(head, tail, val);
        }
        else if (pos >= size(head))
        {
            cout << "Invalid" << endl;
        }
        else
        {
            insertAtPosition(head, pos, val);
        }
        if (pos < size(head))
        {
            printNormal(head);
            printReverse(tail);
        }
    }

    return 0;
}