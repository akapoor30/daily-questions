class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        vector<int> temp(nums.size());
         temp[0]=nums[0];
        
        for(int i=1;i<nums.size();i++){
            
           
            temp[i]=min(temp[i-1],nums[i]);
            
        }
        stack<int> st;
        for(int j=nums.size()-1;j>=0;j--){
            if(nums[j]>temp[j]){
                while(!st.empty() && st.top()<=temp[j])
                    st.pop();
                 if(!st.empty() && st.top()<nums[j])
                 return 1;
            st.push(nums[j]);
            }
             
        }
            
        
         return 0;
    }
};