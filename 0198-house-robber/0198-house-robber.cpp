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
        int prev2=0;
        int prev=nums[0];
        
        for(int ind=1;ind<n;ind++){
            int pk=nums[ind];
            if(ind>1)pk+=prev2;
            int np=0+prev;
           
            int curr=max(pk,np);
            
            prev2=prev;
            prev=curr;
            
        }
        return prev;
    }
};