class Solution {
public:
    void f(TreeNode* root, int tar, vector<vector<int>>& ans, vector<int>& tmp) {
        if (!root) return;
        
        tar -= root->val;
        tmp.push_back(root->val);
        
        if (!root->left && !root->right && tar == 0) {
            ans.push_back(tmp);
            // No need to continue exploring this path, as it already satisfies the condition
            tmp.pop_back();
            return;
        }
        
        f(root->left, tar, ans, tmp);
        f(root->right, tar, ans, tmp);
        
        tmp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        f(root, targetSum, ans, tmp);
        return ans;
    }
};
