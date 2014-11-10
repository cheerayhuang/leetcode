#include <iostream> 
#include <vector> 
#include <array>
#include <queue>
#include <climits>

using namespace std; 

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    pair<bool, int> IsBalanced_(TreeNode *root) {
        if (!root) {
            return make_pair(true, 0);
        }

        auto res_left = IsBalanced_(root->left); 
        auto res_right = IsBalanced_(root->right);

        auto depth = res_left.second > res_right.second ? res_left.second + 1 : res_right.second +1;

        return make_pair(res_left.first && res_right.first && abs(res_left.second-res_right.second) <=1, depth);
    }

public:
    

    bool isBalanced(TreeNode *root) {
        
        return IsBalanced_(root).first;
    }
};

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
    Solution s;

    TreeNode *t1 = nullptr; 
    array<int, 10> arr = {5, 3, 7, 2};
    for (auto &i : arr) {
        if (i == 0) continue;
        InitializeTree(t1, i);
    }

    cout << s.isBalanced(t1) << endl;

    TreeNode *t4 = nullptr;
    array<int, 10> arr4 = {5, 3, 7, 2, 4, 6, 10};
    for (auto &i : arr4) {
        InitializeTree(t4, i);
    }
    cout << s.isBalanced(t4) << endl;

    TreeNode *t5 = new TreeNode(1);
    TreeNode *t6 = new TreeNode(6);

    t5->left = new TreeNode(2);
    t6->right = new TreeNode{2};

    cout << s.isBalanced(t5) << endl;
    cout << s.isBalanced(t6) << endl;

    t6->right->right = new TreeNode{3};
    t6->right->left = new TreeNode(4);
    cout << s.isBalanced(t6) << endl;
    cout << s.isBalanced(nullptr) << endl;

    return 0;
}

