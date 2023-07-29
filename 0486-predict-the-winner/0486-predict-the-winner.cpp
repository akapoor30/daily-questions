class Solution {
public:
    
    int f(vector<int>& nums,int i,int j,int flag)
    {
        if(i==nums.size() || j==-1)return 0;
        if(i>j){
          return 0;
        }
        
        if(flag==0){
            return max(nums[i]+f(nums,i+1,j,1),nums[j]+f(nums,i,j-1,1));
        }
        else
        {
            return min(-nums[i]+f(nums,i+1,j,0),-nums[j]+f(nums,i,j-1,0));
        }
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int flag=0;
        int ans= f(nums,0,nums.size()-1,flag);
        return ans>=0;
    }
};