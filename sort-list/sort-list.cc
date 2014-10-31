#include <iostream> 
#include <cassert>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
private: 
    ListNode *GetNode(ListNode *head, int step) {
        assert(head != nullptr);
        assert(step < Size(head));
        
        for (int i = 0; i < step; ++i) {
            head = head->next;
        }

        return head;
    }

    int Size(ListNode *head) {
        assert(head != nullptr);

        int l = 1;
        while(head = head->next) {
            ++l;    
        }

        return l;
    }

    int MakeMaxHeap(ListNode *head, int i, int l) {
        auto left = 2 * i + 1;
        auto right = 2 * i + 2;
        ListNode *l_node;
        ListNode *r_node;
        ListNode *father = GetNode(head, i);
        ListNode *cur_changed = father;
        auto max = father->val;

        if (left < l) {
           l_node = GetNode(head, left); 
           if (l_node ->val > max) {
               max = l_node ->val;
               cur_changed = l_node;
               i = left;
           }
        }

        if (right < l) {
            r_node = GetNode(head, right); 
            if (r_node->val > max) {
               max = r_node->val;
               cur_changed = r_node;
               i = right;
            }
        }

        if (cur_changed == father) {
            return 0;
        }

        cur_changed->val = father->val;
        father->val = max; 
        
        MakeMaxHeap(head, i, l);
    }

public:
    ListNode *sortList(ListNode *head) {
        if (!head || Size(head) == 1) {
            return head;
        }

        auto l = Size(head);
        for (auto i = l / 2; i >= 0; --i) {
            MakeMaxHeap(head, i, l);        
        }

        for (auto i = 0; i < l; ++i) {
            auto tail = GetNode(head, l-1-i); 
            auto before_tail = GetNode(head, l-2-i);

            if (before_tail == head) {
                head->next = tail->next;
                tail->next = head;
                head = tail;
                break;
            }

            auto tmp = tail->next;
            tail->next = head->next;
            before_tail->next = head; 
            head->next = tmp;

            head = tail;
            MakeMaxHeap(head, 0, l-1-i);
        }

        return head; 
    }
};

void MakeList(ListNode *l) {

    for (auto i = 2; i <= 3; ++i) {
        l->next = new ListNode(i);
        l = l->next;
    }    

}

int main() {
    ListNode *l = new ListNode(1);

    MakeList(l);

    Solution s;

    l = s.sortList(l);

    while (l) {
        cout << l->val << " ";
        l = l->next;
    }

    return 0;
}

