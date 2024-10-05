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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)return ans;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag=1;
        
        while(!q.empty()){
            int size=q.size();
            vector<int> row(size);
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                row[i]=node->val;
                
                if(node->left!=NULL){
                    q.push(node->left);
                }
                
                if(node->right!=NULL){
                    q.push(node->right);
                }
            }
            
            if(flag==1){
                ans.push_back(row);
                flag=0;
            }
            else{
                reverse(row.begin(),row.end());
                ans.push_back(row);
                flag=1;
            }
        }
        return ans;
    }
    
};