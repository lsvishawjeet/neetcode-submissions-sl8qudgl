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
    int height(TreeNode* root, bool& res){
        if(!root) return 0;
        int leftHeight = height(root->left, res);
        int rightHeight = height(root->right, res);
        if(abs(leftHeight-rightHeight)>1){
            res = false;
        }
        return 1+max(leftHeight, rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        bool res = true;
        height(root, res);
        return res;
    }
};
