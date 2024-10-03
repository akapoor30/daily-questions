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
    vector<int> preorderTraversal(TreeNode* root) {
        
        vector<int> vec;
        if(root==NULL)return vec;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            vec.push_back(st.top()->val);
            TreeNode* node=st.top();
            st.pop();
            
            if(node->right!=NULL)st.push(node->right);
            if(node->left!=NULL)st.push(node->left);
        }
        
        return vec;
    }
};