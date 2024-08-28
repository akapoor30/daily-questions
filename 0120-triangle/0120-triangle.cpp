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
        vector<int> front(n,0);
        vector<vector<int>> dp(n,vector<int>(n,0));
        // int mini=INT_MAX,int z=-1;
        for(int j=0;j<n;j++){
            front[j]=triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            vector<int> cur(n,0);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+front[j];
                int dia=triangle[i][j]+front[j+1];
        
                 cur[j]=min(down,dia);
            }
            front=cur;
        }
        
        
        
        return front[0];
    }
};