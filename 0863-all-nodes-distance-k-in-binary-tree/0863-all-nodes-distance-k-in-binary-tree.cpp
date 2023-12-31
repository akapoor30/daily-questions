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
    
    void makeParent(TreeNode* root,unordered_map<TreeNode* ,TreeNode*>& parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                parent_track[node->left]=node;
                q.push(node->left);
                
            }
            
            if(node->right){
                parent_track[node->right]=node;
                q.push(node->right);
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*> parent_track;
        makeParent(root,parent_track);
        
        queue<TreeNode*> q;
        q.push(target);
        
        unordered_map<TreeNode*,bool> visited;
        
        visited[target]=1;
        
        int dis=0;
        
        while(!q.empty()){
            
            int size=q.size();
            
            if(dis==k)break;
            dis++;
            
            
            for(int i=0;i<size;i++){
                TreeNode* curr=q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left]=1;
                }
                
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right]=1;
                }
                
                if(parent_track[curr] && !visited[parent_track[curr]]){
                    q.push(parent_track[curr]);
                    visited[parent_track[curr]]=1;
                }
            }
            
        }
        
        vector<int> ans;
        
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            ans.push_back(temp->val);
            // q.pop();
        }
        return ans;
    }
};