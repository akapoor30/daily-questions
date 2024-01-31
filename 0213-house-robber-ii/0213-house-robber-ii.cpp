class Solution {
    
      int f(int index,vector<int>& nums,vector<int>& dp){
        if(index==0)
            return nums[0];
        if(index<0)
            return 0;
        if(dp[index]!=-1)return dp[index];
        
        
        int pick=nums[index]+f(index-2,nums,dp);
        int np = 0 + f(index-1,nums,dp);
        
        return dp[index]= max(np,pick);
    }
    
    
   int f1(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(n-1,nums,dp);
    }
    
public:
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        
        int n=nums.size();
        
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
            
        }
        
        return max(f1(temp1),f1(temp2));
    }
};