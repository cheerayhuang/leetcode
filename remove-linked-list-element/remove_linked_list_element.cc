/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        auto p = head;
        auto prev = head;
        
        while(p) {
            if (p->val == val) {
                if (p == head) {
                    head = head->next;
                    delete p;
                    p = head;
                    prev = head;
                    continue;
                }
                prev->next = p->next;
                auto tmp = p; 
                p = p->next;
                delete tmp;
                continue;
            }
            prev = p;
            p = p->next;
        }
         return head;
    }
};
