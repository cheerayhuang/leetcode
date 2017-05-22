/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: palindrome_linked_list.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-22-2017 12:10:43
 * @version $Revision$
 *
 **************************************************************************/
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == nullptr) return true;
        auto p = head;
        vector<int> v1, v2;

        while (p) {
            v1.push_back(p->val);
            p = p->next;
        }

        reverse_copy(v1.begin(), v1.end(), back_inserter(v2));


        return v1 == v2;
    }
};


int main() {
    ListNode *h = new ListNode(1);
    h->next = new ListNode(2);
    h->next->next = new ListNode(1);

    Solution s;

    cout << s.isPalindrome(h) << endl;
    return 0;
}


