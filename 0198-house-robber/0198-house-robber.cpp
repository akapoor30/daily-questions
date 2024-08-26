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
        //space optimization
        // vector<int> dp(nums.size(),0);
        int prev=nums[0];
        int prev2=0;
        
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1)take+=prev2;
            int notTake=prev;
            
            int curr=max(take,notTake);
            
            prev2=prev;
            prev=curr;
        }
        
        return prev;
        
    }
};