#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *prev;
    ListNode *next;
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
}

class Solution
{
public:
    bool isPlaindrome(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast != nullptr && fast->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast != nullptr)
        {
            slow = slow->next;
        }
        slow = reverseList(slow);
        fast = head;

        while (slow != nullptr)
        {
            if (fast->val != slow->val)
                return false;

            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }

private:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = nullptr;
        while (head != nullptr)
        {
            ListNode *next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
}

int
main()
{
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int value;

    while (cin >> value && value != -1)
    {
        ListNode *newNode = new ListNode(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        Solution solution;
        if (solution.isPalindrome(head))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }

        return 0;
    }