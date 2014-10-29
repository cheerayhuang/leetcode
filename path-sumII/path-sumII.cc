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
    typedef struct {
        TreeNode *t;
        int f;
        int s;
    }Node;

    vector<int> RecordRes(const vector<Node> &q, int index) {
        vector<int> r{(q[index].t)->val}; 
        auto i = q[index].f; 

        while (i != -1) {
            r.insert(r.begin(), (q[i].t)->val);  
            i = q[i].f;
        }

        return r;
    }

public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        if (!root) {
            return vector<vector<int> >(0);
        }

        vector<Node> q;

        q.push_back({root, -1, root->val});
        int i = 0;
        int res_total = 0;
        vector<vector<int> > res;

        while(i <= q.size()-1) {
            auto t = q[i].t; 
            auto s = q[i].s;

            if (t->left) {
                q.push_back({t->left, i, s + t->left->val});
            }
            if (t->right) {
                q.push_back({t->right, i, s + t->right->val});
            } 
            if (!t->left && !t->right && s == sum) {
                res.push_back(RecordRes(q, i));
            }
            ++i;
        }

        return res; 
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

    auto r = s.pathSum(t, 2);

    for (auto &i : r[0]) {
        cout << i << ' ';
    }
    cout << endl;

    return 0;
}

