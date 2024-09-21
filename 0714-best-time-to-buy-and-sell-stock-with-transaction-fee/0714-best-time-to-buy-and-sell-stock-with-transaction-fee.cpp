class Solution {
public:
     int f(int ind,int buy,int n,vector<int>& arr,int fee,vector<vector<int>> dp){
        
        if(ind==n)return 0;
         
         if(dp[ind][buy]!=-1)return dp[ind][buy];
        
        int profit=INT_MAX;
        
        if(buy){
            profit=max(-arr[ind]+f(ind+1,0,n,arr,fee,dp),0+f(ind+1,1,n,arr,fee,dp));
        }
        else{
            profit=max(arr[ind]-fee+f(ind+1,1,n,arr,fee,dp) ,0+f(ind+1,0,n,arr,fee,dp));
        }
        
        return dp[ind][buy]=profit;
        }
    int maxProfit(vector<int>& arr, int fee) {
         int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        vector<int> ahead(2,0),curr(2,0); 
        for(int ind = n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                int profit=INT_MIN;
        
                if(buy){
                    profit=max(-arr[ind]+ahead[0],0+ahead[1]);
                }
                else{
                    profit=max(arr[ind]-fee+ahead[1] ,0+ahead[0]);
                }

                    curr[buy]=profit;
            }
            ahead=curr;
        }
        
        
        return  ahead[1];
    }
};