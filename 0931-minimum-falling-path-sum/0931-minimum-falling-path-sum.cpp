class Solution {
public:


    int minFallingPathSum(vector<vector<int>>& arr) {
        int n=arr.size();
        int mini=INT_MAX;
        vector<vector<int>> dp(n ,vector<int> (n));
        
        for(int i=0;i<n;i++){
            dp[0][i]=arr[0][i];

        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int leftD=0;
                int rightD=0;
                int up=arr[i][j]+dp[i-1][j];
                if(j-1>=0)leftD=arr[i][j]+dp[i-1][j-1];
                else leftD=1e9;
                if(j+1<n)rightD=arr[i][j]+dp[i-1][j+1];
                else rightD=1e9;
                int minim=min(up,leftD);
                dp[i][j]=min(minim,rightD);
            }
        }
        for(int i=0;i<n;i++){
            mini=min(mini,dp[n-1][i]);
        }
        return mini;
    }
};