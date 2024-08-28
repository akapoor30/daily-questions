class Solution {
public:
    
    
    int f(int i,int j,vector<vector<int>> &arr,vector<vector<int>> &dp){
        int n=arr.size();
        
        if(i==n-1){
            return arr[n-1][j];
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int down=arr[i][j]+f(i+1,j,arr,dp);
        int dia=arr[i][j]+f(i+1,j+1,arr,dp);
        
        return dp[i][j]=min(down,dia);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,triangle,dp);
    }
};