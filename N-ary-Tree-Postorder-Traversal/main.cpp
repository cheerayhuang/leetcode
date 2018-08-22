/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        
        if (root == nullptr) return res;
        

        for(auto iter = (root->children).begin(); iter != (root->children).end(); ++iter) {
            auto v = postorder(*iter);
            

                res.insert(res.end(), v.begin(), v.end());
        }
        
        res.push_back(root->val); 
        return res;
        
    }
};
