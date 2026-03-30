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
    vector<int> rightSideView(TreeNode* root) {
        // algorithm / intution
        
        queue<TreeNode*> q;
        vector<int> sol;
        if(!root) return sol;
        q.push(root);
        while(!q.empty()){
            int sizeOfq = q.size();
            int temp;
            for(int i=0; i<sizeOfq; i++){
                // update the temp as we are moving to right
                auto qFront = q.front();
                temp = qFront->val;
                if(qFront->left) q.push(qFront->left);
                if(qFront->right) q.push(qFront->right);
                q.pop();
            }
            sol.push_back(temp);
        }
        return sol;
    }
};
