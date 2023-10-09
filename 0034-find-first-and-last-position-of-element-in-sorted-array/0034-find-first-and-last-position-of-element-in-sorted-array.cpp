class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vec(2,-1);
        int s=0,e=nums.size()-1;
        int m;
        
       
        
        while(s<=e){
            m=s+(e-s)/2;
            
            if(nums[m]>target){
                e=m-1;
            }
            else if(nums[m]<target)
                s=m+1;
            else{
                vec[0]=m;
                e=m-1;
            }
        }
         s=0;
        e=nums.size()-1;
        while(s<=e){
            m=s+(e-s)/2;
            
            if(nums[m]>target){
                e=m-1;
            }
            else if(nums[m]<target)
                s=m+1;
            else{
                vec[1]=m;
                 s=m+1;
            }
            
        }
        
        
        
        return vec;
    }
};