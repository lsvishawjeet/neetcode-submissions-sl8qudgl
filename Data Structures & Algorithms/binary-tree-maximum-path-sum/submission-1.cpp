/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int res = INT_MIN;
    int traversePath(TreeNode* node){
        if(!node) return 0;
        int left = max(0, traversePath(node->left));
        int right = max(0, traversePath(node->right));
        int path = node->val + left + right;
        res = max(res, path);
        return node->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        traversePath(root);
        return res;
    }
};
