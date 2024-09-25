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
    
    
    int f(int i,int n, string s,  vector<int> &dp){
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
        
        vector<int> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            int mini=2001;
            for(int j=i;j<n;j++){

                if(isPalindrome(s,i,j)){
                    int cost=1+dp[j+1];
                    mini=min(mini,cost);
                }
            }
             dp[i]=mini;
        }
        
        return dp[0]-1;
    }
};