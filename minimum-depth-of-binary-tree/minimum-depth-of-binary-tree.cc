#include <iostream> 
#include <vector> 
#include <array>
#include <queue>

using namespace std; 

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    int minDepth(TreeNode *root) {
        using Leaf = struct Leaf{
            TreeNode *node; 
            int depth;
        };

        if (root == nullptr) {
            return 0;
        }
        
        queue<Leaf> q;
        q.push({root, 1});

        while (!q.empty()) {
            auto cur_node = q.front();
            auto cur_tree_node = cur_node.node; 
            bool flag_new_node = false;
            if (cur_tree_node->left) {
                q.push({cur_tree_node->left, cur_node.depth+1});
                flag_new_node = true;
            } 
            if (cur_tree_node->right) {
                q.push({cur_tree_node->right, cur_node.depth+1});
                flag_new_node = true;
            }

            if (!flag_new_node) {
                return cur_node.depth;
            }

            q.pop();
        }
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
        InitializeTree(t1, i);
    }

    cout << s.minDepth(t1) << endl;

    TreeNode *t4 = nullptr;
    array<int, 10> arr4 = {5, 3, 7, 2, 4, 6, 10};
    for (auto &i : arr4) {
        InitializeTree(t4, i);
    }
    cout << s.minDepth(t4) << endl;

    TreeNode *t5 = new TreeNode(1);
    TreeNode *t6 = new TreeNode(6);

    t5->left = new TreeNode(2);
    t6->right = new TreeNode{2};

    return 0;
}

