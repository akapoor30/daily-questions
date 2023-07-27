class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k=k%nums.size();
        reverse(nums.end()-k,nums.end());
        reverse(nums.begin(),nums.begin()+nums.size()-k);
        reverse(nums.begin(),nums.end());
    }
};