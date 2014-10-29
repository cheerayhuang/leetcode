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


public:
    typedef struct {
        TreeNode *t;
        int s;
    }Node;

    bool hasPathSum(TreeNode *root, int sum) {
        if (!root) {
            return false;
        }

        queue<Node> q;

        q.push({root, root->val});

        while(!q.empty()) {
            auto t = q.front().t; 
            auto s = q.front().s;
            q.pop();

            if (t->left) {
                q.push({t->left, s + t->left->val});
            }
            if (t->right) {
                q.push({t->right, s + t->right->val});
            } 
            else if (!t->left && !t->right && s == sum) {
                return true;
            }
        }

        return false; 
    }
};

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
    
    TreeNode *t; 
    InitializeTree(t, queue<int>({1, -2, -3, 1, 3, -2, -1000, -1}));

    cout << s.hasPathSum(t, 2) << endl;
    cout << s.hasPathSum(t, -1) << endl;
    cout << s.hasPathSum(nullptr, 0) << endl;

    return 0;
}

