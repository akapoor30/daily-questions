class Solution {
public:
    
    int lcs(int ind1,int ind2,string s1,string s2,vector<vector<int>> &dp){
        if(ind1<0 || ind2<0)return 0;
        
        if(dp[ind1][ind2]!=-1)return dp[ind1][ind2];
        
        if(s1[ind1]==s2[ind2])return dp[ind1][ind2]=1+lcs(ind1-1,ind2-1,s1,s2,dp);
        
        return dp[ind1][ind2]=max(lcs(ind1,ind2-1,s1,s2,dp),lcs(ind1-1,ind2,s1,s2,dp));
        
    }
    
    
    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> prev(m+1,0),curr(m+1,0);
        
        
        for(int ind1=1;ind1<=n;ind1++){
            for(int ind2=1;ind2<=m;ind2++){
                 if(s1[ind1-1]==s2[ind2-1]) curr[ind2]=1+prev[ind2-1];
        
                else curr[ind2]=max(curr[ind2-1],prev[ind2]);
        
            }            
            prev=curr;
        }
        
        int LCS=prev[m];
        
        int deletion=n-LCS;
        int insertion=m-LCS;
        
        return deletion + insertion;
    }
};