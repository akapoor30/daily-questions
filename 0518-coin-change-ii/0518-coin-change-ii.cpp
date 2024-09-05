class Solution {
public:
    
    int f(int ind,int tar,vector<int> &nums,vector<vector<int>> &dp){
        if(ind==0){
            return (tar%nums[0]==0);
        }
        
        if(dp[ind][tar]!=-1)return dp[ind][tar];        
        int nt=f(ind-1,tar,nums,dp);
        int p=0;
        if(tar>=nums[ind]){
            p=f(ind,tar-nums[ind],nums,dp);
            
        }
        
        return dp[ind][tar]=p+nt;
    }
    
    
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        return f(n-1,amount,coins,dp);
    }
};