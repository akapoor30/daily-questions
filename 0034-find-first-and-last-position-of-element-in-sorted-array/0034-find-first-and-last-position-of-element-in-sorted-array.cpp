class Solution {
    
    
    //proper binary search
    
    int firstOCC(vector<int>& nums, int target){
        int low=0,high=nums.size()-1;
        int first=-1;
        
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return first;
    }
    
    
        int lastOCC(vector<int>& nums, int target){
        int low=0,high=nums.size()-1;
        int last=-1;
        
        
        while(low<=high){
            int mid=(low+high)/2;
            
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]>target){
                high=mid-1;
            }
            else {
                low=mid+1;
            }
        }
        return last;
    }
    
    
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int lb=firstOCC(arr,target);
        if(lb==-1)return {-1,-1};
        

        int ub=lastOCC(arr,target);
        
        return {lb,ub};
        
    }
};