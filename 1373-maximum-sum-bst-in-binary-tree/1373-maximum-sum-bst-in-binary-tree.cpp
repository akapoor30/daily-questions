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

class NodeValue{
    public:
    int minNode,maxNode,maxSum;
    
    NodeValue(int minNode,int maxNode,int maxSum){
        this->minNode=minNode;
        this->maxNode=maxNode;
        this->maxSum=maxSum;
        
    }
    
};

class Solution {
public:
    int globalSum=0;
    NodeValue f(TreeNode* root){
        if(!root)return NodeValue(INT_MAX,INT_MIN,0);
        
        auto left=f(root->left);
        auto right=f(root->right);
        
        if(left.maxNode<root->val && root->val<right.minNode){
            int curr=root->val+left.maxSum+right.maxSum;
            
            globalSum=max(globalSum,curr);
            
            return NodeValue(min(left.minNode,root->val),max(right.maxNode,root->val),curr);
        }
        return NodeValue(INT_MIN,INT_MAX,0);
    }
    
    int maxSumBST(TreeNode* root) {
     
        f(root);
        return globalSum;
    }
};