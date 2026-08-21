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
    int maxiDep(TreeNode*root){
        int total = 0;
        int left = 0;
        int right = 0;
        if(root->left){
            left = 1 + maxiDep(root->left);
        }
        if(root->right){
            right = 1 + maxiDep(root->right);
        }
        total = max(left, right);
        return total;
    }
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        return maxiDep(root)+1;
    }
};
