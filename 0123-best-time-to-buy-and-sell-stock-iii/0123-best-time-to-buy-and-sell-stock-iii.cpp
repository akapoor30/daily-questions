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
        vector<int> ahead(5,0),curr(5,0);
        for(int ind = n-1; ind>=0;ind--){
            for(int buy = 3;buy>=0;buy--){
                
                     int profit=INT_MAX;
        
                    if(buy%2==0){
                        profit = max(-arr[ind]+ahead[buy+1], 0 + ahead[buy]);
                    }
                    else{
                        profit = max(arr[ind]+ahead[buy+1]
                                     , 0 + ahead[buy]);
                    }
                     curr[buy]=profit;
                
            }
            ahead=curr;
        }
        
        
        return ahead[0];
    }
};