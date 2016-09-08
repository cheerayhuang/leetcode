/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: invert_binary_tree.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-08-2016 11:38:38
 * @version $Revision$
 *
 **************************************************************************/


#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* InitTree(TreeNode*& root, int i) {
        if (!root) {
            root = new TreeNode(i);
            return root;
        }

        if (i > root->val) {
            InitTree(root->right, i);
        }
        else {
            InitTree(root->left, i);
        }

        return root;
    }

    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        swap(root->left, root->right);

        if (root->left) {
            invertTree(root->left);
        }

        if (root->right) {
            invertTree(root->right);
        }

        return root;
    }
};

int main() {
    Solution s;

    TreeNode *r;

    int a[5] = {3, 2, 4, 1, 5};
    for (auto i = 1; i < 6; ++i) s.InitTree(r, a[i-1]);

    cout << r -> val << endl;
    cout << r -> left -> val << endl;
    cout << r -> right->val << endl;
    cout << r -> left ->left-> val << endl;
    cout << r -> right-> right ->val << endl;

    s.invertTree(r);

    cout << r -> val << endl;
    cout << r -> left -> val << endl;
    cout << r -> right->val << endl;
    cout << r -> left ->left-> val << endl;
    cout << r -> right-> right ->val << endl;

    return 0;
}

