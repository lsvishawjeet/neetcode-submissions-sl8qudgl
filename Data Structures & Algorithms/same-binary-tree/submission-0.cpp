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
    void isSame(TreeNode* p, TreeNode* q, bool& res){
        if(p==nullptr && q==nullptr){
            return;
        }
        if(p==nullptr && q!=nullptr || q==nullptr && p!=nullptr){
            res = false;
            return;
        }
        if(p->val != q->val){
            res = false;
            return;
        }
        isSame(p->left, q->left, res);
        isSame(p->right, q->right, res);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool res = true;
        isSame(p, q, res);
        return res;
    }
};
