/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    void makeparents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp1){
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            
            if(node->left){
                mp1[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                mp1[node->right]=node;
                q.push(node->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> mp1;
        
        makeparents(root,mp1);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        int cur=0;
        vis[target]=1;
        q.push(target);
        
        while(!q.empty()){
            int size=q.size();
            if(cur++==k)break;
            // cur++;
            
            for(int i=0;i<size;i++){
                 TreeNode* node=q.front();
                 q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left]=1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=1;
                    q.push(node->right);
                }
                if(mp1[node] && !vis[mp1[node]]){
                    vis[mp1[node]]=1;
                    q.push(mp1[node]);
                }
                
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};