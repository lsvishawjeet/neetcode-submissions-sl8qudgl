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
    void invertNodes(TreeNode* root){
        if(!root) return;
        if(root->left && root->right){
            TreeNode* left = root->left;
            root->left = root->right;
            root->right = left;
        } else if(root->left){
            root->right = root->left;
            root->left = nullptr;
        } else if(root->right){
            root->left = root->right;
            root->right = nullptr;
        }
        invertNodes(root->left);
        invertNodes(root->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertNodes(root);
        return root;
    }
};
