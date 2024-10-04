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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> pre,post,in;
        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        
        if(root==NULL)return {};
        
        while(!st.empty()){
            auto node=st.top();
            st.pop();
            if(node.second==1){
                node.second++;
                st.push(node);
                pre.push_back(node.first->val);
            
                if(node.first->left!=NULL){
                    st.push({node.first->left,1});
                }
            }
            else if(node.second==2){
                node.second++;
                st.push(node);
                in.push_back(node.first->val);
            
                if(node.first->right!=NULL){
                    st.push({node.first->right,1});
                }
            }
            else{
                post.push_back(node.first->val);
            }
        }
        
        return post;
    }
};