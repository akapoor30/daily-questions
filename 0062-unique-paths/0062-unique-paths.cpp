class Solution {
public:
    
    
    int f(int i,int j, vector<vector<int>> &dp){
        if(i==0&& j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        int up=f(i-1,j,dp);
        int down=f(i,j-1,dp);
        
        return dp[i][j]=up+down;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    prev[j]=1;
                }else{
                    int up=0,down=0;
                    if(i>0) up=prev[j];
                    if(j>0) down=prev[j-1];
                    prev[j]=up+down;
                }
                
            }
        }
        
        return prev[n-1];
    }
};