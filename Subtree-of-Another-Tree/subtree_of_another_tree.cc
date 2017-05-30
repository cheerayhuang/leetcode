/**************************************************************************
 *
 * Copyright (c) 2015 Cheeray Huang. All Rights Reserved
 *
 * @file: subtree_of_another_tree.cc
 * @author: Huang Qiyu
 * @email: cheeray.huang@gmail.com
 * @date: 05-29-2017 14:55:21
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

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
    void InorderTree(TreeNode* t, vector<int>*v) {

        if (t->left) {
            InorderTree(t->left, v);
        }

        v->push_back(t->val);

        if (t->right) {
            InorderTree(t->right, v);
        }
    }

    void PostorderTree(TreeNode* t, vector<int>*v) {
        if (t->left) {
            PostorderTree(t->left, v);
        }

        if (t->right) {
            PostorderTree(t->right, v);
        }

        v->push_back(t->val);
    }

    void PreorderTree(TreeNode* t, vector<int>*v) {
        v->push_back(t->val);

        if (t->left) {
            PreorderTree(t->left, v);
        }

        if (t->right) {
            PreorderTree(t->right, v);
        }

        v->push_back(t->val);
    }

    bool LayerOrderSearch(TreeNode *s, TreeNode *t) {
        queue<TreeNode*> q;

        q.push(s);
        while (!q.empty()) {
            auto h = q.front();
            q.pop();
            if (h->left == nullptr && h->right == nullptr && h->val == t->val) {
                return true;
            }

            if (h->left) {
                q.push(h->left);
            }

            if (h->right) {
                q.push(h->right);
            }
        }
        return false;
    }

public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (s == nullptr && t == nullptr) return true;
        if (s == nullptr || t == nullptr) return false;

        vector<int> v1, v2;
        PostorderTree(s, &v1);
        PostorderTree(t, &v2);

        if (v2.size() == 1) {
            return LayerOrderSearch(s, t);
        }

        bool b1 = false;
        if (search(v1.begin(), v1.end(), v2.begin(), v2.end()) != v1.end()) {
            b1 = true;
        }

        v1.clear();
        v2.clear();
        InorderTree(s, &v1);
        InorderTree(t, &v2);

        bool b2 = false;
        if (search(v1.begin(), v1.end(), v2.begin(), v2.end()) != v1.end()) {
            b2 = true;
        }

        v1.clear();
        v2.clear();
        PreorderTree(s, &v1);
        PreorderTree(t, &v2);

        bool b3 = false;
        if (search(v1.begin(), v1.end(), v2.begin(), v2.end()) != v1.end()) {
            b3 = true;
        }

        return b1 && b2 && b3;
    }
};

int main() {
    TreeNode *t = new TreeNode(3);
    t->left = new TreeNode(4);
    t->right = new TreeNode(5);
    t->left->left = new TreeNode(1);
    t->left->right = new TreeNode(2);
    t->right->right = new TreeNode(6);
    t->left->left->left = new TreeNode(0);

    /*
    TreeNode *s = new TreeNode(4);
    s->left = new TreeNode(1);
    s->right = new TreeNode(2);
    */

    //TreeNode *s = new TreeNode(4);
    TreeNode *s = new TreeNode(5);
    s->right = new TreeNode(6);

    Solution ss;
    cout << ss.isSubtree(t, s) << endl;

    return 0;
}

