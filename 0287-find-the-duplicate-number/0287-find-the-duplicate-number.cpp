class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        
        
        for(auto i:mp){
            if(i.second>=2)
                return i.first;
        }
        return 0;
    }
};