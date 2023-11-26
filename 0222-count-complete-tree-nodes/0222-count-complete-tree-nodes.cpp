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
    
    
    int countleft(TreeNode* root){
        int ans=0;
        while(root){
            ans++;
            root=root->left;
        }
        return ans;
    }
    
     int countright(TreeNode* root){
        int ans=0;
        while(root){
            ans++;
            root=root->right;
        }
        return ans;
    }
    
  int countNodes(TreeNode* root) 
    {    
        if(root==NULL) return 0;
      
        int lh=countleft(root);
      int rh=countright(root);
      
      if(lh==rh)return (1<<lh)-1;
      
      
      
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};