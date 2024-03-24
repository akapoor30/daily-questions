class Solution {
public:
    int f(vector<int>& nums,int target,int low,int high){
        if(low>high)return -1;
        
        int mid=(low+high)/2;
        
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]<target){
            return f(nums,target,mid+1,high);
        }
        return f(nums,target,low,mid-1);
    }
    int search(vector<int>& nums, int target) {
        return f(nums,target,0,nums.size()-1);
    }
};