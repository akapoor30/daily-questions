class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long ans=0;
        priority_queue<int> pq;
        
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int temp=0;
        while(k!=0 ){
          ans+=pq.top();
            int t=pq.top();
            pq.pop();
            // cout<<ceil(t/3)<<" ";
            pq.push(ceil((double)t/3));
           k--;
        }
        return ans;
    }
};