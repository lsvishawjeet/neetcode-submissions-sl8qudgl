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
    bool checkIfEqual(TreeNode* root, TreeNode* subRoot){
        if(!root && subRoot) return false;
        if(root && !subRoot) return false;
        if(!root && !subRoot) return true;
        if(root->val != subRoot->val) return false;
        if(root && subRoot){
            if(!checkIfEqual(root->left, subRoot->left)) return false;
            if(!checkIfEqual(root->right, subRoot->right)) return false;
        }
        return true;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(root->val == subRoot->val){
            if(checkIfEqual(root, subRoot)){
                return true;
            }
        }
        if(root->left){
            if(isSubtree(root->left, subRoot)){
                return true;
            }
        }
        if(root->right){
            if(isSubtree(root->right, subRoot)){
                return true;
            }
        }
        return false;
    }
};
