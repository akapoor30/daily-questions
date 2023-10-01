class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count=0,i=nums.size()-1;
        set<int> s;
        
        while(i>=0){
            count++;
            if(nums[i]<=k)s.insert(nums[i]);
            
            if(s.size()==k)return count;
            i--;
        }
        return 0;
    }
};