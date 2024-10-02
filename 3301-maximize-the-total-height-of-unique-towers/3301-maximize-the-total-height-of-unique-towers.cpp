class Solution {
public:
    long long maximumTotalSum(vector<int>& arr) {
        long long sum=0;
        int n= arr.size();
        sort(arr.begin(),arr.end());
        
        
        int prev=INT_MAX;
        for(int i=arr.size()-1;i>=0;i--){
            if(arr[i]<prev){
                sum+=arr[i];
                prev=arr[i];
            }
            else{
                sum+=prev-1;
                prev=prev-1;
            }
            if(prev==0)return -1;
        }
        return sum;
    }
};