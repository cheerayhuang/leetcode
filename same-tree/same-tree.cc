#include <iostream> 
#include <vector> 
#include <array>

using namespace std; 

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {

private:
    void MidOrderIterate(TreeNode *t);
    void PrevOrderIterate(TreeNode *t);

    vector<int> mid_order_;
    vector<int> prev_order_;

public:
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
    }

    mid_order_.push_back(t->val);

    if (t->right) {
        MidOrderIterate(t->right);
    }
}

void Solution::PrevOrderIterate(TreeNode *t) {
    if (not t) {
        return ;
    }

    prev_order_.push_back(t->val);
    if (t->left) {
        PrevOrderIterate(t->left);
    }
    if (t->right) {
        PrevOrderIterate(t->right);
    }
}

void InitializeTree(TreeNode *&t, int val) {
    if (not t) {
        t = new TreeNode(val);
    }

    if (val > t->val) {
        InitializeTree(t->right, val);
    }
    else if (val < t->val) {
        InitializeTree(t->left, val);
    }
}

int main() {
    TreeNode *t1 = nullptr; 
    TreeNode *t2 = nullptr;
    array<int, 10> arr = {5, 3, 7, 2, 4, 6, 8};
    for (auto &i : arr) {
        InitializeTree(t1, i);
        InitializeTree(t2, i);
    }
    Solution s;
    cout << s.isSameTree(t1, t2) << endl;

    TreeNode *t3 = nullptr;
    TreeNode *t4 = nullptr;
    array<int, 10> arr3 = {5, 3, 7, 2, 4, 6, 8};
    array<int, 10> arr4 = {5, 3, 7, 2, 4, 6, 10};
    for (auto &i : arr3) {
        InitializeTree(t3, i);
    }
    for (auto &i : arr4) {
        InitializeTree(t4, i);
    }
    cout << s.isSameTree(t3, t4) << endl;

    TreeNode *t5 = new TreeNode(1);
    TreeNode *t6 = new TreeNode(6);

    t5->left = new TreeNode(2);
    t6->right = new TreeNode{2};

    cout << s.isSameTree(t5, t6) << endl;

    return 0;
}

