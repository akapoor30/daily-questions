class Solution {
public:
    
    bool isPalindrome(string &s,int i,int j){
        
        while(i<=j){
            if(s[i]!=s[j])return 0;
            i++;
            j--;
        }
        return 1;
    }
    
    
    int f(int i,int n, string &s,  vector<int> &dp){
        if(i==n)return 0;
        
        if(dp[i]!=-1)return dp[i];
       
        int mini=1e9;
        for(int j=i;j<n;j++){
          
            if(isPalindrome(s,i,j)){
                int cost=1+f(j+1,n,s,dp);
                mini=min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
    
    int minCut(string s) {
        int n=s.size();
        
        vector<int> dp(n,-1);
        
        return f(0,n,s,dp) -1;
    }
};