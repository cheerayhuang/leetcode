/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: diameter_of_binary_tree.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-30-2017 11:59:54
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

// subtree should be same in preoder, inoder and postoreder.

class Solution {
private:
    int max = 0;

    int IterateTree(TreeNode* t) {
        auto right_deep = 0;
        auto left_deep = 0;

        if (t->left) {
            left_deep = IterateTree(t->left);
            left_deep ++;
        }

        if (t->right) {
            right_deep = IterateTree(t->right);
            right_deep++;
        }

        if (left_deep + right_deep > max) max = right_deep + left_deep;

        return (left_deep > right_deep ? left_deep : right_deep);
    }


public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (rott == nullptr) return 0;
        IterateTree(root);

        return max;
    }
};

int main() {
    TreeNode *t = new TreeNode(3);
    t->left = new TreeNode(4);
    /*t->right = new TreeNode(5);
    t->left->left = new TreeNode(1);
    t->left->right = new TreeNode(2);
    t->right->right = new TreeNode(6);
    t->left->left->left = new TreeNode(0);
    */

    Solution s;
    cout << s.diameterOfBinaryTree(t) << endl;
}

