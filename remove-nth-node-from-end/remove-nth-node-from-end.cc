class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr || n == 0) {
            return head;
        }
        
        auto iter_end = head;
        auto iter = head;
        auto prev_iter = head;
        
        while(n--) {
            iter_end = iter_end->next;
        }
        
        while(iter_end != nullptr) {
            prev_iter = iter;
            iter = iter->next;
            iter_end = iter_end->next;
        }
        
        if (prev_iter == iter) {
            return head->next;
        }
        
        prev_iter->next = iter->next;
        delete iter;
        
        return head;
    }
};
