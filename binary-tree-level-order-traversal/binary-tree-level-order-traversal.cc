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
    vector<vector<int> > levelOrder(TreeNode *root) {
        using Leaf = struct Leaf{
            TreeNode *node; 
            int level;
        };

        if (root == nullptr) {
            return {};
        }
        
        queue<Leaf> q;
        q.push({root, 0});
        auto max_depth = 0;

        vector<vector<int> > result(1);
        result.reserve(100);

        while (!q.empty()) {
            auto cur_node = q.front();
            auto cur_tree_node = cur_node.node; 

            if (cur_node.level > max_depth) {
                max_depth = cur_node.level;
                result.resize(max_depth + 1);
            }

            result[cur_node.level].push_back(cur_tree_node->val);

            if (cur_tree_node->left) {
                q.push({cur_tree_node->left, cur_node.level+1});
            } 
            if (cur_tree_node->right) {
                q.push({cur_tree_node->right, cur_node.level+1});
            }

            q.pop();
        }

        return result;
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

    auto res = s.levelOrder(t1);
    for(auto &i : res) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    TreeNode *t4 = nullptr;
    array<int, 10> arr4 = {5, 3, 7, 2, 4, 6, 10};
    for (auto &i : arr4) {
        if (i == 0) continue;
        InitializeTree(t4, i);
    }
    res = s.levelOrder(t4);
    for(auto &i : res) {
        for (auto &j : i) {
            cout << j << " ";
        }
        cout << endl;
    }

    TreeNode *t5 = new TreeNode(1);
    TreeNode *t6 = new TreeNode(6);

    t5->left = new TreeNode(2);
    t6->right = new TreeNode{2};

    t6->left = new TreeNode{2};


    t6->left->right = new TreeNode(4); 

    return 0;
}

