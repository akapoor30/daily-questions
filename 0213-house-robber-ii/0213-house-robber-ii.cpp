class Solution {
    
int f1(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        int prev2=0;
        int prev=nums[0];
        
        for(int ind=1;ind<n;ind++){
            int pk=nums[ind];
            if(ind>1)pk+=prev2;
            int np=0+prev;
           
            int curr=max(pk,np);
            
            prev2=prev;
            prev=curr;
            
        }
        return prev;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        
        int n=nums.size();
        
        if(n==1)return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0){
                temp1.push_back(nums[i]);
            }
            if(i!=n-1){
                temp2.push_back(nums[i]);
            }
            
        }
        
        return max(f1(temp1),f1(temp2));
    }
};