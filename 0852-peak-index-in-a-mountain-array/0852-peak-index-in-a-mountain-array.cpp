class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1;
        
        if(arr[s]>arr[s+1])
            return s;
        
        if(arr[e]>arr[e-1])
            return e;
        
        int mid;
        
        while(s<=e){
            mid=s+(e-s)/2;
            
            if(arr[mid]<arr[mid+1]){
                s=mid+1;
            }
            else if(arr[mid]>arr[mid+1])
                e=mid-1;
        }
        return s;
    }
};