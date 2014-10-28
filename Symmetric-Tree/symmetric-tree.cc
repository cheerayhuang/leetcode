/**************************************************************************
 *
 * Copyright (c) 2014 Nibirutech, Inc. All Rights Reserved
 * www.Nibirutech.com
 * 
 * @file: symmetric-tree.cc
 * @author: Huang Qiyu
 * @email: huangqiyu@chukong-inc.com
 * @date: 10-28-2014 15:46:34
 * @version $Revision$
 *
 **************************************************************************/

#include <iostream> 
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<int>  mid_order_;
    vector<int> prev_order_;

    void MidOrderIterate(TreeNode *t);    
    void PrevOrderIterate(TreeNode *t);
    TreeNode*  ReverseTree(TreeNode *t) {
        if (not t) {
            return nullptr;
        }

        TreeNode *tmp = new TreeNode(t->val);
        tmp->left = ReverseTree(t->right);
        tmp->right = ReverseTree(t->left);
        
        return tmp;
    }


public:
    bool isSymmetric(TreeNode *root) {
        auto reversed_root = ReverseTree(root);
   
        return isSameTree(root, reversed_root);
    }

    bool isSameTree(TreeNode *p, TreeNode *q) {
        mid_order_.clear();
        prev_order_.clear();
        MidOrderIterate(p);
        PrevOrderIterate(p);
        auto mid_order_p = mid_order_;
        auto prev_order_p = prev_order_;

        mid_order_.clear();
        prev_order_.clear();
        MidOrderIterate(q);
        PrevOrderIterate(q);
        auto mid_order_q = mid_order_;
        auto prev_order_q = prev_order_;

        if (mid_order_p == mid_order_q && prev_order_p == prev_order_q) {
            return true;
        }

        return false;
    }
};

void Solution::MidOrderIterate(TreeNode *t) {
    if (not t) {
        return ;
    }

    if (t->left) {
        MidOrderIterate(t->left);
    } else {
        mid_order_.push_back(-1);
    }
    
    mid_order_.push_back(t->val);

    if (t->right) {
        MidOrderIterate(t->right);            
    } else {
        mid_order_.push_back(-1);
    }

}

void Solution::PrevOrderIterate(TreeNode *t) {
    if (not t) {
        return ;
    }

    prev_order_.push_back(t->val);
    if (t->left) {
        PrevOrderIterate(t->left);
    } else {
        prev_order_.push_back(-1);
    }

    if (t->right) {
        PrevOrderIterate(t->right);
    } else {
        prev_order_.push_back(-1);
    }
}

void InitializeTree(TreeNode *&t, queue<int> vals) {
    TreeNode *n = new TreeNode(vals.front());
    vals.pop();
    t = n; 
    queue<TreeNode **> q; 
    q.push(&t->left); 
    q.push(&t->right);

    while (!vals.empty()) {
        auto tmp = q.front(); 
        q.pop();
        *tmp = new TreeNode(vals.front());
        q.push(&((*tmp)->left));
        q.push(&((*tmp)->right));
        vals.pop();
    }
}

int main() {
    Solution s;
    //cout << s.isSymmetric(nullptr);

    TreeNode *t;

    InitializeTree(t, queue<int>({1, 2, 2, -1, 3, 3, -1}));
    cout << s.isSymmetric(t) << endl;

    return 0;
}

