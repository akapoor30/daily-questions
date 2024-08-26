class Solution {
    
    int f(vector<int> &nums,int ind,vector<int> &dp){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        
          int pick=nums[ind]+f(nums,ind-2,dp);
        
        int notPick=0+f(nums,ind-1,dp);
        
        return dp[ind]=max(pick,notPick);
    }
    
public:
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(),0);
        dp[0]=nums[0];
        int neg=0;
        
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1)take+=dp[i-2];
            int notTake=dp[i-1];
            
            dp[i]=max(take,notTake);
        }
        
        return dp[nums.size()-1];
        
    }
};