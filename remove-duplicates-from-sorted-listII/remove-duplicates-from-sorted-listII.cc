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
        auto prev = head;
        auto isDuplicated = false;
        while (h != nullptr) {
            auto next = h->next; 
            if (next != nullptr && next->val == h->val) {
                h->next = next->next;
                delete next;
                isDuplicated = true;
            }
            else {
                if (isDuplicated) {
                    if (h != head) 
                        prev->next = next;
                    else {
                        head = next;
                        prev = next;
                    }
                    delete h;
                }
                else {
                    prev = h;
                }
                h = next;
                isDuplicated = false;
            }
        }

        return head;
    }
};

int main() {
    ListNode *h = new ListNode{1};
    h->next = new ListNode(1);
    //h->next->next = new ListNode{2};

    Solution s;
    h = s.deleteDuplicates(h);

    if (h == nullptr) {
        cout << "nullptr" << endl; 
    }
    else cout << h->val << endl;

    return 0;
}

