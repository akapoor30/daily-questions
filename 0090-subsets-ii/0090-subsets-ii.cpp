class Solution {
public:
    
    void f(vector<int>& nums, vector<vector<int>> &ans,vector<int> &temp,int ind ){
        // if(ind==nums.size()){
            ans.push_back(temp);
            // return ;
            
        // }
        for(int i=ind;i<nums.size();i++){
            if(i!=ind && nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
                f(nums,ans,temp,i+1);
                temp.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        sort(nums.begin(),nums.end());
        
        f(nums,ans,temp,0);
        
        return ans;
    }
};