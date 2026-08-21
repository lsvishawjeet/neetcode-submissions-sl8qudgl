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
    void dfs(TreeNode* node, int &k, int &sol){
        if(!node) return;
        dfs(node->left, k, sol);
        k--;
        if(k == 0){
            sol = node->val;
            return;
        }
        dfs(node->right, k, sol);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        // min element is on left most
        // reach the left most element -> star counting / dec k
        int sol = 0;
        dfs(root, k, sol);
        return sol;
    }
};
