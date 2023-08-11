class Solution {
public:
    int change(int tar, vector<int>& a) {
        int n=a.size();
        vector<vector< long long int >> dp(n,vector< long long int> (tar+1,0));
        for(int i=0;i<=tar;i++){
            if(i%a[0]==0)dp[0][i]=1;
        
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=tar;j++){
                long long int np=dp[i-1][j];
                 long long int p=0;
                if(a[i]<=j){
                    p=dp[i][j-a[i]];
                    
                }
                 dp[i][j]=p+np;
            }
        }
        return dp[n-1][tar];
    }
};