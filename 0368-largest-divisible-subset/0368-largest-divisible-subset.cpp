class Solution {
public:
    
    vector<int> f(vector<int>& nums ,int n){
        int lastIndex=0;
        vector<int> dp(n,1),hash(n);
        int maxi=INT_MIN;
        
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(nums[i]%nums[prev]==0 && dp[i]<1+dp[prev]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
            
        }
        
        vector<int> vec;
        
        vec.push_back(nums[lastIndex]);
        int ind=1;
        
        
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            vec.push_back(nums[lastIndex]);
            
        }
        
        return vec;
    }
    
    vector<int> largestDivisibleSubset(vector<int>& nums) {
       
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        
        return f(nums,n);
    }
};