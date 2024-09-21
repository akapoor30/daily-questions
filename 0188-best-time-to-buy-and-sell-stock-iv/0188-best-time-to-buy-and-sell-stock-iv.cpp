class Solution {
public:
    
    int f(int ind,int buy,int cap,vector<int>& arr,int n,vector<vector<vector<int>>> &dp){
        
        if(cap==0)return 0;
        if(ind==n)return 0;
        
        if(dp[ind][buy][cap]!=-1)return dp[ind][buy][cap];
        
        int profit=INT_MIN;
        
        if(buy){
            profit= max(-arr[ind]+f(ind+1,0,cap,arr,n,dp),0 + f(ind+1,1,cap,arr,n,dp));
        }else{
            profit= max(arr[ind]+f(ind+1,1,cap-1,arr,n,dp),0 + f(ind+1,0,cap,arr,n,dp));
        }
        return dp[ind][buy][cap]=profit;
    }
    
    
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        
        
        return f(0,1,k,prices,n,dp);
    }
};