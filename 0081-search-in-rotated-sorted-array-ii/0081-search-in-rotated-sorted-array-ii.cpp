class Solution {
public:
    bool search(vector<int>& arr, int target) {
         int s=0,e=arr.size()-1;
        int mid;
        while(s<=e){
            mid=(s+e)/2;
            if(arr[mid]==target)return 1;
            
            
            if(arr[mid]==arr[s] && arr[mid]==arr[e]){
                s=s+1;
                e=e-1;
                continue;
            }
            
            if(arr[s]<=arr[mid]){
                if(arr[s]<=target && target<=arr[mid]){
                    e=mid-1;
                }
                else {
                    s=mid+1;
                }
            }
            else {
                if(target>=arr[mid] && target<=arr[e]){
                    s=mid+1;
                }
                else {
                    e=mid-1;
                }
            }
        }
        return 0;
    }
};




// [4,5,6,7,0,1,2]