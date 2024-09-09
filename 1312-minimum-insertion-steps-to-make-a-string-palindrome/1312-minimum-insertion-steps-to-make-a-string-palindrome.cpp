class Solution {
public:
    
    int f(int i,int j,string s1,string s2,vector<vector<int>> &dp){
        
        if(i<0 || j<0) return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s1[i]==s2[j])return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
        
        return dp[i][j]=max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    
    
    int minInsertions(string s1) {
        int n=s1.size();
        string s2=s1;
        
        reverse(s1.begin(),s1.end());
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
        
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        int lps=dp[n][n];
        
        return n-lps;
    }
};