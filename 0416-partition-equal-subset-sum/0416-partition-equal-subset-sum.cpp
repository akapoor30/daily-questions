class Solution {
public:
    
    
    bool f(int ind,int target,vector<int>& nums,vector<vector<int>> &dp){
        
        if(target==0)return 1;
        if(ind==0)return nums[0] == target;
        
        if(dp[ind][target]!=-1)return dp[ind][target];
        
        bool nt=f(ind-1,target,nums,dp);
        bool t=0;
        if(target>=nums[ind]){
            t=f(ind-1,target - nums[ind],nums,dp);
        }
        
        return dp[ind][target]=t|nt;
        
    }
    
    
    bool canPartition(vector<int>& nums) {
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        
        int n=nums.size();
        int s=sum/2;
        
        vector<vector<int>> dp(n,vector<int>(s+1,-1));
        
        if(sum%2)return 0;
        return f(n-1,sum/2,nums,dp);
    }
};