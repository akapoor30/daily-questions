class Solution {
public:
    
    int f(vector<int>& nums, int target,vector<int> &dp){
        
        
            if(target==0){
                return 1;
            }
        
            if(target<0){
                return 0;
            }
        
        if(dp[target]!=-1)return dp[target];
        
        int c1=0,c2=0;
       for(int i=0;i<nums.size();i++){
            c1  += f(nums,target-nums[i],dp);
                                                       
        }
           
        
        return dp[target]=c1;
    }
    
    
    int combinationSum4(vector<int>& nums, int target) {
        int ans=0;
        vector<int> dp(target+1,-1);
        return f(nums,target,dp);
    }
};