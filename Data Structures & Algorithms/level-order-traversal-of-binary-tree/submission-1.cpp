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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> sol;
        if(!root) return sol;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> vec;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr = q.front();
                q.pop();
                vec.push_back(curr->val);
                if(curr->left) q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            sol.push_back(vec);
        }
        return sol;
    }
};
