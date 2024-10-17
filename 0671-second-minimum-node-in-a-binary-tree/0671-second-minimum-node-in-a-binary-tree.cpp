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
    int findSecondMinimumValue(TreeNode* root) {
        
        
        
        if(!root)return -1;
        
       
        
        long long  firstMin=root->val;
        long long  secondMin=LLONG_MAX;
        
        TreeNode* curr=root;
        
        while(curr){
            if(curr->left==NULL){
                if(curr->val>firstMin && curr->val<secondMin)secondMin=curr->val;
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right && prev->right!=curr){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=curr;
                    curr=curr->left;
                }
                else{
                    prev->right=NULL;
                    if(curr->val>firstMin && curr->val<secondMin){
                        secondMin=curr->val;
                    }
                    curr=curr->right;
                }
            }
        }
        return secondMin==LLONG_MAX ? -1 : secondMin;
    }
};