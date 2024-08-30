class Solution {
public:

    bool f(int ind,int tar,vector<int>& nums,vector<vector<int>> &dp){
        if(tar==0)return 1;
        if(ind==0) return (nums[0]==tar);
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        bool nt=f(ind-1,tar,nums,dp);
        bool t=0;
        if(nums[ind]<=tar){
            t=f(ind-1,tar-nums[ind],nums,dp);
        }
        return dp[ind][tar]=t|nt;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++) sum+=nums[i];
        
        vector<vector<int>> dp(nums.size(),vector<int> (sum/2+1,-1));
        if(sum%2)return 0;
        return f(nums.size()-1,sum/2,nums,dp);
    }
};