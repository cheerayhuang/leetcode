#include <iostream> 

using namespace std; 

struct ListNode {
    int val;

    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *h = nullptr;
        ListNode *h_next = nullptr;
        
        if (l1 == l2) {
            return l1;
        }

        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val > l2->val) {
                auto tmp = l1; 
                l1 = l2;
                l2 = tmp;
            }

            auto next_l1 = l1->next;

            if (!h) {
                h = l1;
                h_next = h;
            }
            else {
                h_next->next = l1;
                h_next = h_next->next;
            }

            l1 = next_l1;
        }
        
        if (h_next == nullptr) {
            if (l2 == nullptr) {
                return l1;
            }
            return l2;
        }

        h_next->next = l2;

        return h;
    }
};

int main() {
    ListNode *h1 = new ListNode(2);
    auto h = h1;
    for(auto i = 4; i <= 10; i = i + 2) {
        h->next = new ListNode(i); 
        h = h->next;
    }

    ListNode *h2 = new ListNode(7);
    h = h2; 
    for (auto i = 3; i <= 1; i = i+2) {
        h->next = new ListNode(i);
        h = h->next;
    }

    Solution s;

    h = s.mergeTwoLists(nullptr, h2);
    
    while(h != nullptr) {
        cout << h->val << " ";
        auto p = h;
        h = h->next;
        delete p;
    }

    return 0;
}

