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
    int countGood(TreeNode* root, int preMax){
        if(!root) return 0;
        int sol = (preMax<=root->val) ? 1 : 0;
        preMax = max(preMax, root->val);
        sol += countGood(root->left, preMax);
        sol += countGood(root->right, preMax);
        return sol;
    }
    int goodNodes(TreeNode* root) {
        return countGood(root, root->val);;
    }
};
