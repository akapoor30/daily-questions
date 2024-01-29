class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int e=nums.size()-2;
        
        while(e>=0){
            if(nums[e]<nums[e+1])
                break;
            e--;
        }
        int index1=e;
        e=nums.size()-1;
        // cout<<index1;
        if(index1==-1)
            index1=0;
        
        while(e>=0){
            if(nums[e]>nums[index1])
                break;
            e--;
        }
        int index2=e;
        // cout<<index1<<" "<<index2;
          if(index2==-1)
              sort(nums.begin(),nums.end());
        
        
        else{
        swap(nums[index2],nums[index1]);
        
        reverse(nums.begin()+index1+1,nums.end());
        }
    }
};