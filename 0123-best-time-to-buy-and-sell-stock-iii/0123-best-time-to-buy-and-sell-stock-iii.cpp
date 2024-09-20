class Solution {
public:
    
    int f(int ind,int buy,int cap,vector<int>& arr,int n,vector<vector<vector<int>>> &dp){
        if(cap==0)return 0;
        if(ind==n)return 0;
        
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        
        int profit=INT_MAX;
        
        if(buy){
            profit = max(-arr[ind]+f(ind+1,0,cap,arr,n,dp), 0 + f(ind+1,1,cap,arr,n,dp));
        }
        else{
            profit = max(arr[ind]+f(ind+1,1,cap-1,arr,n,dp), 0 + f(ind+1,0,cap,arr,n,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n+1,vector<int>(5,0));
        
        for(int ind = n-1; ind>=0;ind--){
            for(int buy = 3;buy>=0;buy--){
                
                     int profit=INT_MAX;
        
                    if(buy%2==0){
                        profit = max(-arr[ind]+dp[ind+1][buy+1], 0 + dp[ind+1][buy]);
                    }
                    else{
                        profit = max(arr[ind]+dp[ind+1][buy+1]
                                     , 0 + dp[ind+1][buy]);
                    }
                     dp[ind][buy]=profit;
                
            }
        }
        
        
        return dp[0][0];
    }
};