class Solution {
public:
    
    int f(int ind, int prev_ind , vector<int>& nums,int n,vector<vector<int>> &dp){
        if(ind==n)return 0;
        
        if(dp[ind][prev_ind+1]!=-1)return dp[ind][prev_ind+1];
        
        int nt= 0 + f(ind+1, prev_ind, nums,n,dp);
        int t=INT_MIN;
        
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            t = 1 + f(ind+1,ind,nums,n,dp);
        }
        
        return dp[ind][prev_ind+1]=max(t,nt);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                 int nt= 0 + dp[ind+1][prev_ind+1];
                int t=INT_MIN;

                if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                    t = 1 + dp[ind+1][ind+1];
                }

                 dp[ind][prev_ind+1]=max(t,nt);
            }
        }
        
        return dp[0][0];
    }
};