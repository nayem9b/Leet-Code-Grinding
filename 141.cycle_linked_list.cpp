class Solution {
public:
    bool hasCycle(ListNode* head) {
        unordered_set<ListNode*> visited;

        ListNode* curr = head;
        while (curr != NULL) {
            if (visited.find(curr) != visited.end()) {
                return true;
            }
            visited.insert(curr);
            curr = curr->next;
        }
        return false;
    }
};                  