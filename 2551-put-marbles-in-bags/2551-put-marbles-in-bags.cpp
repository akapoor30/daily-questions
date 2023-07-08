class Solution {
public:
    long long putMarbles(vector<int>& arr, int k) {
        priority_queue<long long> maxp;
        priority_queue<long long, vector<long long> ,greater<long long>> minp;
        k--;
        for(int i=0;i<arr.size()-1;i++){
            maxp.push(arr[i]+arr[i+1]);
            minp.push(arr[i]+arr[i+1]);
        }
        long long ans=0;
        while(k>0){
            ans+=maxp.top()-minp.top();
            maxp.pop();
            minp.pop();
            k--;
        }
        return ans;
    }
};