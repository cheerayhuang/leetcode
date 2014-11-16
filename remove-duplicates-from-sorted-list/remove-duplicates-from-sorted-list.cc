#include <iostream> 

using namespace std; 

struct ListNode {
    int val;

    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == nullptr) {
            return head;
        }

        auto h = head;
        while (h != nullptr) {
            auto next = h->next; 
            if (next != nullptr && next->val == h->val) {
                h->next = next->next;
                delete next;
            }
            else {
                h = next;
            }
        }

        return head;
    }
};

int main() {

    return 0;
}
