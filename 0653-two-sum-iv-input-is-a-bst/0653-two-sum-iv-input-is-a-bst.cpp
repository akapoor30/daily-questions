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
class BSTIterator {
public:
    stack<TreeNode*> st;
    
    bool reserve=true;
    BSTIterator(TreeNode* root,bool isReserve) {
        reserve=isReserve;
        push(root);
    }
    
    int next() {
        TreeNode* node=st.top();
        st.pop();
       if(!reserve) push(node->right);
        else push(node->left);
        return node->val;
        
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void push(TreeNode* root){
        for(;root!=NULL; ){
            st.push(root);
            if(reserve==true){
                root=root->right;
            }
            else{
                root=root->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)return 0;
        
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        
        int i=l.next();
        int j=r.next();
        
        while(i<j){
            if(i+j==k)return 1;
            if(i+j<k)i=l.next();
            else{
               j= r.next();
            }
        }
        return 0;
    }
};