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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* r=new TreeNode(val);
            if(root)  r->left=root;
            return r;
        }
        queue<TreeNode*> q;
        q.push(root);
        int c=0;
        
        while(!q.empty()){
            int size=q.size();
            c++;
            for(int i=0;i<size;i++){
                if(c+1==depth){
                    auto k=q.front(); q.pop();
                    TreeNode *l=NULL, *r=NULL;
                    if(k->left) l=k->left;
                    if(k->right)  r=k->right;
                    
                    k->left=new TreeNode(val);
                    k->left->left=l;
                    k->right=new TreeNode(val);
                    k->right->right=r;
                    
                    q.push(k->left);
                    q.push(k->right);
                }
                else{
                    auto k=q.front(); q.pop();
                    
                    if(k->left) 
                        q.push(k->left);
                    if(k->right)  
                        q.push(k->right);
                }
            }
        }
        return root;
    }
};