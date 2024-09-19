class Solution {
public:
    
    int f(int ind,int n,vector<int>& arr,int buy,vector<vector<int>> &dp){
        
        if(ind==n)return 0;
        
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        
        int profit=INT_MAX;
        
        if(buy){
            profit=max(-arr[ind]+f(ind+1,n,arr,0,dp),0+f(ind+1,n,arr,1,dp));
        }
        else{
            profit=max(arr[ind]+f(ind+1,n,arr,1,dp),0+f(ind+1,n,arr,0,dp));
        }
        
        return dp[ind][buy]=profit;
        }
        
        
        
    
    
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2,-1));
        
        return f(0,n,prices,1,dp);
    }
};