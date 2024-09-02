class Solution {
public:
    
    int f(int ind,int tar,vector<int>& coins,vector<vector<int>> &dp){
        if(ind==0){
            if(tar%coins[0]==0)return  tar/coins[0];
            else return 1e9;
        }
        
        if(dp[ind][tar]!=-1)return dp[ind][tar];
        
        int np=0+f(ind-1,tar,coins,dp);
        int p=1e9;
        
        
        if(tar>=coins[ind]){
            p=1+f(ind,tar-coins[ind],coins,dp);
        }
        
        return dp[ind][tar]=min(p,np);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,(vector<int>(amount+1,0)));
        
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=i/coins[0];
            }
            else{
                dp[0][i]=1e9;
            }
        }
        
        
        for(int ind=1;ind<n;ind++){
            for(int tar=0;tar<=amount;tar++){
                 int np=0+dp[ind-1][tar];
                int p=1e9;


                if(tar>=coins[ind]){
                    p=1+dp[ind][tar-coins[ind]];
                }

                 dp[ind][tar]=min(p,np);
            }
        }
        
        int ans= dp[n-1][amount];
        if(ans>=1e9)return -1;
        return ans;
    }
};