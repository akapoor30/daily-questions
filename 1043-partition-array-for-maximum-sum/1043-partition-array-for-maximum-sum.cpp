class Solution {
public:
    
    int f(int i, int n, vector<int> &arr,int k,vector<int> &dp){
        if(i==n)return 0;
        if(dp[i]!=-1)return dp[i];
        int maxi=-1e9,len=0,maxANS=-1e9;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum = (maxi*len) + f(j+1,n,arr,k,dp);
            
            maxANS = max(maxANS, sum);
            
        }
        return dp[i]=maxANS;
        
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n,-1);
        return f(0,n,arr,k,dp);
    }
};