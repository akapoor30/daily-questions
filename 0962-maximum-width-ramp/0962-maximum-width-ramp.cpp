class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        
        stack<int> st;
        
        int maxi=0;
        
        for(int i=0;i<vec.size();i++){
            if(st.empty()){
                st.push(vec[i].second);
            }
            else{
                if(st.top()<vec[i].second)
                    maxi=max(maxi,vec[i].second-st.top());
                else  st.push(vec[i].second);
            }
        }
        return maxi;
    }
};