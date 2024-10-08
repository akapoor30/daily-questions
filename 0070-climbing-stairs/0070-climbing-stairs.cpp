class Solution {
public:
    
    int f(int n,vector<int> &dp){
        if(n<=1)return 1;
        
        if(dp[n]!=-1)return dp[n];
        
        
        int l=f(n-1,dp);
        int r=f(n-2,dp);
        
        return dp[n]=l+r;
        
    }
    
    
    int climbStairs(int n) {
        vector<int> dp(n+1,0);
        
        int prev=1;
        int prev2=1;
        
        for(int i=2;i<=n;i++){
            int cur=prev+prev2;
            
            
            prev2=prev;
            prev=cur;
            // dp[i]=dp[i-1]+dp[i-2];
        }
        
        return prev;
    }
};