class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head==null)
        {
          return null;
        }
        if (head->next ==null)
        {
           return null
        }
        ListNode preNode =null;
        listNode currNode= head;
        while (currNode!=null)
        {
           ListNode nextNode= currNode.next;
           currNode.next=preNode;
           preNode = currNode;
           currNode =nextNode;
        }
        head = preNode;
        return head;
    }
};