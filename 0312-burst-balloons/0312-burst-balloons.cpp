class Solution {
public:
    
    int f(int i, int j, vector<int> &nums,vector<vector<int>> &dp){
        if(i>j)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        int maxi= -1e9;
        
        for(int ind=i;ind<=j;ind++){
            int costs = nums[i-1] * nums[ind] * nums[j+1] + f(i,ind-1,nums,dp) + f(ind+1,j,nums,dp);
            maxi=max(maxi,costs);
        }
        
        return dp[i][j]=maxi;
            
    }
    
    
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        
        for(int i=n;i>=1;i--){
            for(int j=i;j<=n;j++){
                 int maxi= -1e9;
                // if(i>j)continue;
                for(int ind=i;ind<=j;ind++){
                    int costs = nums[i-1] * nums[ind] * nums[j+1] + dp[i][ind-1] + dp[ind+1][j];
                    maxi=max(maxi,costs);
        }
        
         dp[i][j]=maxi;
            }
        }
        
        return dp[1][n];
    }
};