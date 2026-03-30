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
    void countGood(TreeNode* root, int& count, int preMax){
        if(!root) return;
        if(root->val >= preMax){
            count++;
        }
        preMax = max(preMax, root->val);
        countGood(root->left, count, preMax);
        countGood(root->right, count, preMax);
    }
    int goodNodes(TreeNode* root) {
        // je tu root node to x node te jana hove and os vich koi v element root and x node to small na hove then oh good node aa
        int count = 0;
        countGood(root, count, root->val);
        return count;
    }
};
