class Solution {
public:
    
    void per(vector<int> &nums,vector<vector<int>> &ans,int ind, vector<int> &temp){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            per(nums,ans,ind+1,temp);
             swap(nums[i],nums[ind]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        // vector<int> freq(nums.size(),0);
        per(nums,ans,0,temp);
        
        return ans;
    }
};