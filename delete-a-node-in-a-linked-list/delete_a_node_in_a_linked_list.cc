/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: delete_a_node_in_a_linked_list.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-08-2016 13:33:38
 * @version $Revision$
 *
 **************************************************************************/

/**
 *  * Definition for singly-linked list.
 *   * struct ListNode {
 *    *     int val;
 *     *     ListNode *next;
 *      *     ListNode(int x) : val(x), next(NULL) {}
 *       * };
 *        */

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {

    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {

        auto p = node;

        while (p->next->next != NULL) {
            p->val = p->next->val;
            p = p->next;
        }

        p->val = p->next->val;
        delete(p->next);
        p->next = NULL;
    }
};

void InitListNode(ListNode*& n, int i) {

    if (!n) {
        n = new ListNode(i);
        return ;
    }

    auto p = n;

    while (p->next) {
        p = p->next;
    }

    p->next = new ListNode(i);
}

void Print(ListNode *n) {
    while (n) {
        cout << n->val << endl;
        n = n->next;
    }
}

int main() {
    ListNode *n = nullptr;
    for (auto i = 1; i < 3; ++i) InitListNode(n, i);

    ListNode *d = n;

    Print(n);

    Solution s;
    s.deleteNode(d);

    Print(n);


    return 0;
}

