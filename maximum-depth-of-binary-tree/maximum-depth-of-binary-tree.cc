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
    int maxDepth(TreeNode *root) {
        using Leaf = struct Leaf{
            TreeNode *node; 
            int depth;
        };

        if (root == nullptr) {
            return 0;
        }
        
        queue<Leaf> q;
        q.push({root, 1});
        auto max_depth = 0;

        while (!q.empty()) {
            auto cur_node = q.front();
            auto cur_tree_node = cur_node.node; 
            if (cur_node.depth > max_depth) {
                max_depth = cur_node.depth;
            }

            if (cur_tree_node->left) {
                q.push({cur_tree_node->left, cur_node.depth+1});
            } 
            if (cur_tree_node->right) {
                q.push({cur_tree_node->right, cur_node.depth+1});
            }

            q.pop();
        }

        return max_depth;
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

    cout << s.maxDepth(t1) << endl;

    TreeNode *t4 = nullptr;
    array<int, 10> arr4 = {5, 3, 7, 2, 4, 6, 10};
    for (auto &i : arr4) {
        InitializeTree(t4, i);
    }
    cout << s.maxDepth(t4) << endl;

    TreeNode *t5 = new TreeNode(1);
    TreeNode *t6 = new TreeNode(6);

    t5->left = new TreeNode(2);
    t6->right = new TreeNode{2};
    cout << s.maxDepth(t6) << endl;

    cout << s.maxDepth(nullptr) << endl;

    t6->left = new TreeNode{2};

    cout << s.maxDepth(t6) << endl;

    t6->left->right = new TreeNode(4); 
    cout << s.maxDepth(t6) << endl;

    return 0;
}

