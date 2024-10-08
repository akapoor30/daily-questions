class Solution {
public:
    
    int f(int i,int j,vector<vector<int>> &arr,vector<vector<int>> &dp){
        if(i==0 && j==0){
            return arr[0][0];
        }
        if(i<0 || j<0){
            return 1e9;
        }
        
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int up = arr[i][j]+f(i-1,j,arr,dp);
        int left= arr[i][j]+f(i,j-1,arr,dp);
        
        return dp[i][j]=min(up,left);
    }
    
    
    int minPathSum(vector<vector<int>>& arr) {
        int m=arr.size();
        int n=arr[0].size();
        
        vector<vector<int>> dp(m,vector<int>(n,0));
        vector<int> prev(n,0);
        // prev[0]=arr[0][0];
        
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                
                if(i==0 && j==0) temp[j]=arr[i][j];
                else{
                    int up=0,left=0;
                    
                    
                     if(i>0) up = arr[i][j]+prev[j];
                    else{
                        up=1e9;
                    }
                    if(j>0) left= arr[i][j]+temp[j-1];
                    else{
                        left=1e9;
                    }
                    temp[j]=min(up,left);
                }
               
            }
            prev=temp;
        }
        
        return prev[n-1];
        
    }
};