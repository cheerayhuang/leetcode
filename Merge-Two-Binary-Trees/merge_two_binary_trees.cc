/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: merge_two_binary_trees.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 06-25-2017 21:21:30
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return nullptr;

        if (t2 != nullptr && t1 == nullptr) {
            t1 = t2;
            return t1;
        }

        if (t1 != nullptr && t2 == nullptr) {
            return t1;
        }

        t1->val += t2->val;

        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);

        return t1;
    }
};

void PrintTree(TreeNode *t) {
    if (t == nullptr) return;

    cout << t->val << ' ';

    if (t->left != nullptr) PrintTree(t->left);
    if (t->right != nullptr) PrintTree(t->right);
}

int main() {
    TreeNode *t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->left->left = new TreeNode(3);

    TreeNode *t2 = new TreeNode(1);
    t2->right = new TreeNode(2);
    t2->right->right = new TreeNode(3);

    Solution s;

    t1 = s.mergeTrees(t1, t2);

    PrintTree(t1);

    return 0;
}
