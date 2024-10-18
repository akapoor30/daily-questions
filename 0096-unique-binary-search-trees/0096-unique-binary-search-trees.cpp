class Solution {
public:
    
    
//     int f(int n,vector<int> &dp){
//         if(n<=1){
//             return 1;
            
//         }
        
//         if(dp[n]!=-1)return dp[n];
        
//     }
    
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[1]=1;dp[0]=1;
        for(int ind=2;ind<=n;ind++){
            int ans=0;
            for(int i=1;i<=ind;i++){
                ans+=dp[i-1]*dp[ind-i];
            }
             dp[ind]=ans;
        }
        return dp[n];
    }
};