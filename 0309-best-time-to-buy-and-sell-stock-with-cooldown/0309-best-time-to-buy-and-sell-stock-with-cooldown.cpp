class Solution {
public:
    
    int f(int ind,int buy,vector<int>& arr,int n,vector<vector<int>> &dp){
        if(ind>=n)return 0;
        
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        
        int profit=INT_MIN;
        
        if(buy){
            profit = max(-arr[ind]+f(ind+1,0,arr,n,dp), 0 + f(ind+1,1,arr,n,dp));
        }
        else{
            profit= max(arr[ind] + f(ind+2,1,arr,n,dp),0 + f(ind+1,0,arr,n,dp));
        }
        
        return dp[ind][buy]=profit;
    }
    
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        
        for(int ind = n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=INT_MIN;
        
                if(buy){
                    profit = max(-arr[ind]+dp[ind+1][0], 0 + dp[ind+1][1]);
                }
                else{
                    profit= max(arr[ind] + dp[ind+2][1],0 + dp[ind+1][0]);
                }

                 dp[ind][buy]=profit;
            }
        }
        
        return dp[0][1];
    }
};