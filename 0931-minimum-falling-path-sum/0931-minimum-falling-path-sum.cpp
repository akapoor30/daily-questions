class Solution {
public:
    
    int f(int i,int j,vector<vector<int>> &arr,int n,vector<vector<int>> &dp){
        
        if(j<0 || j>=n){
            return 1e9;
        }
        
        if(i==0){
           return arr[0][j];
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int s=arr[i][j]+ f(i-1,j,arr,n,dp);
        int ld = arr[i][j] + f(i-1,j-1,arr,n,dp);
        int rd = arr[i][j] + f(i-1,j+1,arr,n,dp);
        
       
        
         int mini=min(s,ld);
        return dp[i][j]=min(mini,rd);
    }
    
    
    int minFallingPathSum(vector<vector<int>>& arr) {
        int n = arr.size();
        
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int j=0;j<n;j++){
            dp[0][j]=arr[0][j];
        }
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int ld,rd;
                int s=arr[i][j]+ dp[i-1][j];
                if(j-1>=0) ld = arr[i][j] + dp[i-1][j-1];
                else{
                    ld=1e9;
                }
                if(j<n-1) rd = arr[i][j] + dp[i-1][j+1];
                else{
                    rd=1e9;
                }
                dp[i][j]=min(s,min(ld,rd));
            }
        }
        
        
        
        int mini = INT_MAX;
        for(int i=0;i<n;i++){
            mini= min(mini,dp[n-1][i]);
        }
        return mini;
    }
};