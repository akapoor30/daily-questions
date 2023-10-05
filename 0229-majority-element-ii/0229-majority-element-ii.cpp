class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<int> vec;
        int n=nums.size();
        
        for(auto i : mp){
            if(i.second>n/3){
                vec.push_back(i.first);
            }
        }
        return vec;
    }
};