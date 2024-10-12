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
    
    
    TreeNode* makeParent(TreeNode* root,int start, unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        TreeNode* temp;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->val==start){
                temp=node;
            }
            
            if(node->left){
                q.push(node->left);
                parent[node->left]=node;
            }
            
            if(node->right){
                q.push(node->right);
                parent[node->right]=node;
            }
        }
        return temp;
    }
    
    int f(TreeNode* root,TreeNode* target,unordered_map<TreeNode*,TreeNode*> &parent){
        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool> vis;
        vis[target]=1;
        
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int temp=0;
            
            for(int i=0;i<size;i++){
                TreeNode* node=q.front();
                q.pop();
                
                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left]=1;
                    temp=1;
                }
                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right]=1;
                    temp=1;
                }
                if(parent[node] && !vis[parent[node]]){
                    q.push(parent[node]);
                    vis[parent[node]]=1;
                    temp=1;
                }
               
            }
             if(temp)ans++;
        }
        return ans;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* tar=makeParent(root,start,parent);
        int ans=f(root,tar,parent);
        
        return ans;
    }
};