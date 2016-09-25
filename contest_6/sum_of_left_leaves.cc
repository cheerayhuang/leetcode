/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: sum_of_left_leaves.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-25-2016 09:32:52
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
private:
    enum {left, right};
    short current_pos = left;

public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (!root) return 0;
        auto l = 0;
        auto r = 0;

        if (!root->left && !root->right) {
            if (current_pos == left) return root->val;
            return 0;
        }

        auto old_pos = current_pos;
        if (root->left) {
            current_pos = left;
            l = sumOfLeftLeaves(root->left);
            current_pos = old_pos;
        }
        if (root->right) {
            current_pos = right;
            r = sumOfLeftLeaves(root->right);
            current_pos = old_pos;
        }

        return l+r;
    }
};

void Init(TreeNode* & root, int i) {
    if (!root) {
        root = new TreeNode(i);
        return ;
    }

    if (i < root->val) {
        Init(root->right, i);
    }

    if (i > root->val) {
        Init(root->left, i);
    }
}

int main() {
    TreeNode * root = nullptr;

    for(auto i = 0; i < 10; ++i) {
        Init(root, i);
    }

    Solution s;

    cout << s.sumOfLeftLeaves(root) << endl;

    return 0;
}

