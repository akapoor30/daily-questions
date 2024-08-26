class Solution {
public:
    
     int f(vector<int> &nums,int ind, vector<int> &dp){
        if(ind==0){
            return nums[ind];
        }
        if(ind<0){
            return 0;
        }
         
        if(dp[ind]!=-1)return dp[ind];
        
          int pick=nums[ind]+f(nums,ind-2,dp);
        
        int notPick=0+f(nums,ind-1,dp);
        
        return dp[ind]=max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        
        vector<int> vec1,vec2;
        
        vector<int> dp1(nums.size()-1,-1),dp2(nums.size()-1,-1);
        
        vec1.push_back(nums[0]);
        if(nums.size()==1)return nums[0];
        for(int i=1;i<nums.size()-1;i++){
          
            vec1.push_back(nums[i]);
            vec2.push_back(nums[i]);
        }
        
        vec2.push_back(nums[nums.size()-1]);
        
        return max(f(vec1,nums.size()-2,dp1),f(vec2,nums.size()-2,dp2));
    }
};