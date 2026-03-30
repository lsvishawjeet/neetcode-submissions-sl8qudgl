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
        queue<pair<TreeNode*, int>> tq;
        vector<vector<int>> sol;
        if(root == nullptr) return sol;
        tq.push({root,0});
        while(!tq.empty()){
            auto front = tq.front();
            auto node = front.first;
            int level = front.second;
            if(sol.size()<=level){
                sol.push_back({node->val});
            } else{
                sol[level].push_back(node->val);
            }
            tq.pop();
            if(node->left != nullptr){
                tq.push({node->left, 1+level});
            }
            if(node->right != nullptr){
                tq.push({node->right, 1+level});
            }
        }
        return sol;
    }
};
