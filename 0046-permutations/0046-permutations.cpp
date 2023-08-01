class Solution {
public:
    
    void f(int ind,vector<int>& nums,vector<vector<int>> &ans,vector<int> &tmp){
        if(ind==nums.size()){
            ans.push_back(nums);
            return ;
            
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            f(ind+1,nums,ans,tmp);
            swap(nums[i],nums[ind]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        f(0,nums,ans,tmp);
        return ans;
    }
};