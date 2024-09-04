class Solution {
public:
    
    
    int f(int ind,int tar,vector<int>& nums,vector<vector<int>> &dp){
        // if(tar==0)return 1;
        if(ind==0){
            if(nums[0]==0 && tar==0)return 2;
            if(tar==0 || nums[0]==tar)return 1;
            return 0;
        }
        
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        
        int nt=f(ind-1,tar,nums,dp);
        int t=0;
        if(tar>=nums[ind]){
            t=f(ind-1,tar-nums[ind],nums,dp);
        }
        
        return dp[ind][tar]=t+nt;
        
    }
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        
        
        for(auto i:nums){
            sum+=i;
        }
        int s=(sum-target)/2;
        if(sum-target<0 || (sum-target)%2)return 0;
        int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(s+1,0));
        
        
        if(nums[0]==0)dp[0][0]=2;
        else dp[0][0]=1;
        
        if(nums[0]!=0 && s>=nums[0]){
            dp[0][nums[0]]=1;
            
        }
        
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=s;tar++){
                int nt=dp[ind-1][tar];
                int t=0;
                if(tar>=nums[ind]){
                    t=dp[ind-1][tar-nums[ind]];
                }

                 dp[ind][tar]=t+nt;
            }
        }
        
        return dp[n-1][s];
    }
};