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
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        vector<vector<int>> ahead(2,vector<int>(3,0));
        vector<vector<int>> curr(2,vector<int>(3,0));
        
        for(int ind = n-1; ind>=0;ind--){
            for(int buy = 0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                     int profit=INT_MAX;
        
                    if(buy){
                        profit = max(-arr[ind]+ahead[0][cap], 0 + ahead[1][cap]);
                    }
                    else{
                        profit = max(arr[ind]+ahead[1][cap-1]
                                     , 0 + ahead[0][cap]);
                    }
                     curr[buy][cap]=profit;
                }
            }
            ahead=curr;
        }
        
        
        return ahead[1][2];
    }
};