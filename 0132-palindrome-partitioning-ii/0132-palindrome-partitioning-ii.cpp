class Solution {
public:
    
    bool isPalindrome(string s,int i,int j){
        
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
        int n = s.size();
        if (n <= 1) return 0;

        // Create a table to store palindrome status
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));
        
        // Every single character is a palindrome
        for (int i = 0; i < n; ++i) {
            isPalindrome[i][i] = true;
        }

        // Check for 2 character palindromes
        for (int i = 0; i < n - 1; ++i) {
            isPalindrome[i][i + 1] = (s[i] == s[i + 1]);
        }

        // Check for palindromes longer than 2 characters
        for (int length = 3; length <= n; ++length) {
            for (int i = 0; i <= n - length; ++i) {
                int j = i + length - 1;
                isPalindrome[i][j] = (s[i] == s[j]) && isPalindrome[i + 1][j - 1];
            }
        }

        vector<int> dp(n + 1, INT_MAX);
        dp[n] = -1; // Base case: no cuts needed for an empty suffix

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                if (isPalindrome[i][j]) {
                    dp[i] = min(dp[i], 1 + dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
};