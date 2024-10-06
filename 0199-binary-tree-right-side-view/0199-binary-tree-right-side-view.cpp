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
    
    void f(TreeNode* root,vector<int>& ans,int level){
        if(root==NULL)return;
        
        if(level==ans.size()){
            ans.push_back(root->val);
            
        }
        if(root->right){
            f(root->right,ans,level+1);
        }
        if(root->left){
            f(root->left,ans,level+1);
            
        }
        
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)return ans;
        
       queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            ans.push_back(q.front()->val);
            int size=q.size();
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                
                if(node->right){
                    q.push(node->right);
                }
                if(node->left){
                    q.push(node->left);
                }
            }
        }
        
        return ans;
    }
};