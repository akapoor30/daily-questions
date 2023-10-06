class Solution {
public:

    int integerBreak(int n) {
        
        vector<int> dp(n+1,0);
        dp[1]=1;
        
        
        for(int num=2;num<=n;num++){
             int res;
            if(num==n)res=0;
            else res=num;

            for(int i=1;i<=num;i++){
                int val=i*dp[num-i];
               res=max(res,val);
            }
             dp[num]=res;
            }
        return dp[n];
    }
};