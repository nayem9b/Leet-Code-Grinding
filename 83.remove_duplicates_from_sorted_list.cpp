class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; // If the list is empty or has only one element, no duplicates can exist
        }
        
        ListNode* prev = head;
        ListNode* temp = head->next;
        
        while (temp != nullptr) {
            if (temp->val == prev->val) {
                ListNode* duplicate = temp;
                temp = temp->next;
                delete duplicate; // Delete the duplicate node
            } else {
                prev->next = temp;
                prev = temp;
                temp = temp->next;
            }
        }
        
        prev->next = nullptr; // Terminate the list
        return head;
    }
};
