class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mp[sum]=i;
        }
        
        if(x>sum)
            return -1;
        
        
        
        int val=0,longVal=0;
        mp[0]=0;
        int rest=sum-x;
        
        for(int i=0;i<nums.size();i++){
            
            val+=nums[i];
            
            if(mp.count(val-rest)){
                if(val-rest==0){
                    longVal=max(longVal,i-mp[val-rest]+1);
                }
                else
                    longVal=max(longVal,i-mp[val-rest]);
            }
            
        }
        if(longVal==0)
            if(rest==0)
            return nums.size();
             else
             return -1;
        // cout<<longVal;
         return nums.size()-longVal;
        // return longVal==0?( rest==0?nums.size(): -1):nums.size()-longVal;
    }
};