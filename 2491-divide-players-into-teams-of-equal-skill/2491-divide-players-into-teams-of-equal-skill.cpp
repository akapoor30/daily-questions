class Solution {
public:
    long long dividePlayers(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        long long ans=0;
        
        if(arr.size()==2)return arr[0]*arr[1];
        int sum=arr[0]+arr[arr.size()-1];
        ans+=arr[0]*arr[arr.size()-1];
        int i=1,j=arr.size()-2;
        while(i<j){
            if(sum!=arr[i]+arr[j])return -1;
            else{
                 ans+=arr[i]*arr[j];
            }
            i++;
            j--;
        }
        return ans;
    }
};