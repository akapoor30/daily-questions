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
    
    
    int change(int amount, vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        vector<int> prev(amount+1,0),curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            prev[i]=(i%nums[0]==0);
        }
        
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){
                int nt=prev[tar];
                int p=0;
                if(tar>=nums[ind]){
                    p=curr[tar-nums[ind]];

                }

                 curr[tar]=p+nt;
            }
            
            prev=curr;
        }
        
        return prev[amount];
    }
};