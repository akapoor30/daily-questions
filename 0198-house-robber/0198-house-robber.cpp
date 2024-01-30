//SAME QUESTION AS ADJCENT SUM
class Solution {
public:
    
    int f(int ind,vector<int>& nums,vector<int> &dp){
        if(ind==0)return nums[0];
        if(ind<0)return 0;
        
        if(dp[ind]!=-1)return dp[ind];
        
        
        int pk=nums[ind]+f(ind-2,nums,dp);
        int np=0+f(ind-1,nums,dp);
        
        return dp[ind]=max(pk,np);
    }
    
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        
        dp[0]=nums[0];
        
        for(int ind=1;ind<n;ind++){
            int pk=nums[ind];
            if(ind>1)pk+=dp[ind-2];
            int np=0+dp[ind-1];
            
            dp[ind]=max(pk,np);
        }
        return dp[n-1];
    }
};