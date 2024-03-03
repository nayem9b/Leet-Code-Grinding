class PalindromeLinkedList {
public:
    bool isPalindrome(ListNode* head) {
        // Find the middle
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast != nullptr) { // odd nodes: let right half smaller
            slow = slow->next;
        }

        // Reverse the second half
        slow = reverseList(slow);
        fast = head;

        // Start comparing one by one
        while (slow != nullptr) {
            if (fast->val != slow->val)
                return false;

            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }

private:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head != nullptr) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};
