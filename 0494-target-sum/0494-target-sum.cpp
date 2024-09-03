class Solution {
public:
    
    
    int f(int ind,int tar,vector<int>& nums){
        // if(tar==0)return 1;
        if(ind==0){
            if(nums[0]==0 && tar==0)return 2;
            if(tar==0 || nums[0]==tar)return 1;
            return 0;
        }
        
        int nt=f(ind-1,tar,nums);
        int t=0;
        if(tar>=nums[ind]){
            t=f(ind-1,tar-nums[ind],nums);
        }
        
        return t+nt;
        
    }
    
    
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
        
        
        for(auto i:nums){
            sum+=i;
        }
        int s=(sum-target)/2;
        if(sum-target<0 || (sum-target)%2)return 0;
        int n=nums.size();
        
        return f(n-1,s,nums);
    }
};