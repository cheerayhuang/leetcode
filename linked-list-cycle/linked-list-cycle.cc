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
    bool hasCycle(ListNode *head) {
        auto fast = head;
        auto slow = head;
        
        auto steps = 0;
        while (fast) {
            fast = fast->next;
            ++steps;
            if (fast == slow) return true;
            if (steps % 2 == 0) slow = slow->next;
        }
        
        return false;
    }
};
