/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: trim_a_binary_search_tree.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 09-30-2017 15:47:56
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

/**
Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    public:

    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if (root == nullptr) return root;

        while (root->val < L || root->val > R) {
            if (root->val < L) {
                root = root->right;
            }
            else if (root->val > R) {
                root = root->left;
            }

            if (!root) return root;
        }

        if (root->left) {
            root->left = trimBST(root->left, L, R);
        }

        if (root->right) {
            root->right = trimBST(root->right, L, R);
        }

        return root;
    }
};

void PrintTree(TreeNode *root) {
    if (!root) {
        cout << "null tree!" << endl;
        return;
    }

    class LayerNode {
        public:
        TreeNode* tree;
        int layer;

        LayerNode(TreeNode* t, int l): tree(t), layer(l) {}
    };

    vector<vector<int>> figures;
    deque<LayerNode> points {{root, 0}};
    figures.push_back(vector<int>());
    figures[0].push_back(root->val);

    while (!points.empty()) {
        auto i = points.front();
        points.pop_front();
        auto t = i.tree;
        auto layer = i.layer;

        if (layer+1 > figures.size()-1) {
                figures.push_back(vector<int>());
        }

        if (t->left) {
            points.emplace_back(t->left, layer+1);
            figures[layer+1].push_back(t->left->val);
        }
        if (t->right) {
            points.emplace_back(t->right, layer+1);
            figures[layer+1].push_back(t->right->val);
        }
    }

    for (auto v : figures) {
        for (auto p : v) {
            cout << p << ' ';
        }
        cout << endl;
    }
}

int main() {
    Solution s;

    TreeNode *root = new TreeNode(0);
    //root->left = new TreeNode(4);
    //root->right = new TreeNode(8);

    PrintTree(root);
    root = s.trimBST(root, 6, 8);
    PrintTree(root);

    return 0;
}
