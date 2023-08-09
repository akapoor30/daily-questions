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
     void f(TreeNode* root, int tar,bool& flag, vector<int>& tmp) {
        if (!root) return;
        
        tar -= root->val;
        tmp.push_back(root->val);
        
        if (!root->left && !root->right && tar == 0) {
           
            // No need to continue exploring this path, as it already satisfies the condition
            tmp.pop_back();
            flag=1;
            return ;
        }
        
        f(root->left, tar, flag, tmp);
        f(root->right, tar, flag, tmp);
        
        tmp.pop_back();
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag=0;
         vector<int> tmp;
        
        f(root, targetSum, flag, tmp);
        return flag;
        
    }
};