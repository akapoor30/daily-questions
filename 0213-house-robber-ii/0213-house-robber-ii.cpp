class Solution {
public:
    
   int f(vector<int>& nums) {
        int prev=nums[0];
        int prev2=0;
        
        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if(i>1)take+=prev2;
            int notTake=prev;
            
            int curr=max(take,notTake);
            
            prev2=prev;
            prev=curr;
        }
        
        return prev;
        
        
    }
    int rob(vector<int>& nums) {
        
        vector<int> vec1,vec2;
        
        // vector<int> dp1(nums.size()-1,-1),dp2(nums.size()-1,-1);............
        
        vec1.push_back(nums[0]);
        if(nums.size()==1)return nums[0];
        for(int i=1;i<nums.size()-1;i++){
          
            vec1.push_back(nums[i]);
            vec2.push_back(nums[i]);
        }
        
        vec2.push_back(nums[nums.size()-1]);
        
        return max(f(vec1),f(vec2));
    }
};