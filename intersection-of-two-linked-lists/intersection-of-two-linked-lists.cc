/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: intersection-of-two-linked-lists.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 12-16-2014 11:15:56
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <cstdlib>

using namespace std; 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }

        auto listA = headA; 
        auto listB = headB;
        auto lenA = 1; 
        auto lenB = 1;
        while (listA->next != nullptr) { listA = listA->next; ++lenA; }
        while (listB->next != nullptr) { listB = listB->next; ++lenB; }
        if (listA != listB) {
            return nullptr;
        }

        if (lenA > lenB) {
            listA = headA; 
            listB = headB;
        }
        else {
            listA = headB;
            listB = headA;
        }

        auto i = 0; 
        while (i < abs(lenA-lenB)) {
            listA = listA->next;
            ++i;
        }
        
        while (listA != nullptr && listB != nullptr) {
           if (listA == listB) {
                return listA;
           }

           listA = listA->next;
           listB = listB->next;
        }

        return nullptr;
    }
};

int main() {
    Solution s; 
    ListNode *headB = new ListNode{2};
    headB->next = new ListNode{3};

    auto headA = headB->next;

    auto res = s.getIntersectionNode(headA, headB);

    cout << res->val << endl;

    return 0;
}

