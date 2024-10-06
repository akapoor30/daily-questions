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
    
    bool f(TreeNode* l,TreeNode* r){
        if(l==NULL || r==NULL)return l==r;
        
        if(l->val!=r->val)return 0;
        
        return f(l->right,r->left) && f(l->left,r->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return 1;
        
        return f(root->left,root->right);
    }
};