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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        
        TreeNode* root=f(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,mp);
        
        return root;
    }
    
    TreeNode* f(vector<int>& postorder,int postStart,int postEnd, vector<int>& inorder,int inStart,int inEnd, unordered_map<int,int> &mp){
        if(postStart>postEnd || inStart>inEnd)return NULL;
        
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        int inRoot=mp[postorder[postEnd]];
        int numsleft=inRoot-inStart;
        
        root->left=f(postorder,postStart ,postStart+numsleft-1 , inorder,inStart ,inRoot-1 ,mp);
        root->right=f(postorder,postStart+numsleft,postEnd-1 , inorder,inRoot+1 ,inEnd ,mp);
        
        return root;
    }
};