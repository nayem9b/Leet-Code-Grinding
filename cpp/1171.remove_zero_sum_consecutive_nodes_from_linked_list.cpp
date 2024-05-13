class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(head==NULL){
            return 0;
        }
        unordered_map<int,ListNode*> m;
        ListNode* dummy = new ListNode(0);
        dummy->next=head;
        m[0]=dummy;
        int prefixSum=0;
        while(head!=NULL){
            prefixSum+=head->val;
            if(m.find(prefixSum)!=m.end()){
              ListNode* start =m[prefixSum];
              int sum=prefixSum;
              while(start!=NULL && start!=head){
                start=start->next;
                sum+=start->val;
                if(start!=head){
                    m.erase(sum);
                }
              }
              m[prefixSum]->next=head->next;
            }
            else{
                m[prefixSum]=head;
            }
            head=head->next;
        }
        return dummy->next;
    }
};