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
    void flatten(TreeNode* root) {
        TreeNode* cur=root;
        
        while(cur){
            if(cur->left!=NULL){
                TreeNode* prev=cur->left;
                while(prev->right){
                    prev=prev->right;
                }
                prev->right=cur->right;
                if(cur->left!=NULL)
                    cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
    }
};