class Solution
{
public:
    ListNode *doubleIt(ListNode *head)
    {
        stack<int> stack;
        int val = 0;
        while (head != NULL)
        {
            stack.push(head->val);
            head = head->next;
        }
        ListNode *newTail = NULL;
        while (!stack.empty() || val != 0)
        {
            newTail = new ListNode(0, newTail);
            if (!stack.empty())
            {
                val += stack.top() * 2;
                stack.pop();
            }
            newTail->val = val % 10;
            val /= 10;
        }
        return newTail;
    }
};