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
        int left = traversePath(node->left);
        int right = traversePath(node->right);
        int path = node->val + max(left, right);
        return max(0, path);
    }
    void traverseTree(TreeNode* node){
        if(!node) return;
        int pathVal = node->val + traversePath(node->left) + traversePath(node->right);
        res = max(res, pathVal);
        traverseTree(node->left);
        traverseTree(node->right);
    }
    int maxPathSum(TreeNode* root) {
        traverseTree(root);
        return res;
    }
};
