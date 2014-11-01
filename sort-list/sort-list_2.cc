#include <iostream> 
#include <cassert>
#include <deque>
#include <cstdlib>
#include <ctime>

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

    int MakeMaxHeap(deque<int> &q, int i, int l) {
        auto left = 2 * i + 1;
        auto right = 2 * i + 2;

        auto cur_changed = i; 
        auto max = q[i]; 

        if (left < l && q[left] > max) {
            max = q[left]; 
            cur_changed = left;
        }
        if (right < l && q[right] > max) {
            max = q[right];
            cur_changed = right;
        }

        if (cur_changed == i) {
            return 0;
        }
        
        q[cur_changed] = q[i];
        q[i] = max;

        MakeMaxHeap(q, cur_changed, l);

        return 0;
    }

public:
    ListNode *sortList(ListNode *head) {
        if (!head || Size(head) == 1) {
            return head;
        }

        deque<int> q; 
        auto h = head;
        while(h) {
            q.push_back(h->val);
            h = h->next;
        }

        auto l = q.size(); 
        for (int i = l / 2; i >= 0; --i) {
            MakeMaxHeap(q , i, l);
        }

        for (auto i = 0; i < l; ++i) {
            auto tmp = q[l-1-i];
            q[l-1-i] = q[0];
            q[0] = tmp;

            MakeMaxHeap(q, 0, l-1-i);
        }
        
        h = head;
        while(h) {
           h->val = q.front();
           q.pop_front();
           h = h->next;
        }

        return head; 
    }
};

void MakeList(ListNode *l) {
    srand(time(nullptr));
    for (auto i = 2; i <= 1000000; ++i) {
        l->next = new ListNode(rand()%1000000+1);
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

