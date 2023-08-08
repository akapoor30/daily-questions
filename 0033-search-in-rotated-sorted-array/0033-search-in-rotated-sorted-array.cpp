class Solution {
    int findPivot(vector<int>& nums,int n) {
        int s=0,e=n-1;
        
        int mid=(s+e)/2;
        

        
        while(s<e){
           if(nums[mid]>=nums[0])
               s=mid+1;
            else{
                e=mid;
            }
            
            mid=(s+e)/2;
        }
        return s;
    }
    
    
      int search(vector<int>& nums,int s,int e, int target) {
       
int mid;
    
    while(s<=e){
        mid=(s+e)/2;
        if(nums[mid]==target)
            return mid;
        else if(nums[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        // cout<<mid<<endl;
    }
       return -1;
        //   return mid;
    }
    
public:
     
    
    
    int search(vector<int>& nums, int target) {
     int pivot=findPivot(nums,nums.size());
        cout<<pivot<<endl;
        if(target>=nums[pivot] && target<=nums[nums.size()-1]){
            return search(nums,pivot,nums.size()-1,target);
        }
        
        else{
            return search(nums,0,pivot-1,target);
        }
        return -1;
    }
};