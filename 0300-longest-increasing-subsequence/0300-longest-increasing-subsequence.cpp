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
        // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        vector<int> dp(n,1);
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int prev_ind=0;prev_ind<i;prev_ind++){
                if(nums[prev_ind]<nums[i]){
                    dp[i]=max(dp[i],1+dp[prev_ind]);
                }
            }
            maxi=max(dp[i],maxi);
        }
        
        return maxi;
    }
};