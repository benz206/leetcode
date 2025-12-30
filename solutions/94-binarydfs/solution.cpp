#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<int>& v, TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        if (node->left) {
            dfs(v, node->left);
        }
        v.push_back(node->val);
        if (node->right) {
            dfs(v, node->right);
        }  
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> traversal;

        dfs(traversal, root);

        return traversal;
    }
};
