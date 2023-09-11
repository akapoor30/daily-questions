class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> vec;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]]++;
        }
        
        
        for(auto j:mp){
            int count=0;
            
            vector<int> tmp;
            for(int i=0;i<groupSizes.size();i++){
                if(j.first==groupSizes[i] && count!=j.first){
                    count++;
                    // groupSizes[i]-=1;
                    tmp.push_back(i);
                }
                if(count==j.first){
                    vec.push_back(tmp);
                    count=0;
                    tmp.clear();
                }
                
            }
        }
        
        return vec;
        
    }
};