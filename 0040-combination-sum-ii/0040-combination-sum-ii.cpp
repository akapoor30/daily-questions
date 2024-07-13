class Solution {
    
    void comb2(vector<int>& candidates, int target,vector<vector<int>> &ans,vector<int> &temp,int ind){
       
        if(target==0){
            ans.push_back(temp);
            return ;
        }
        
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1])continue;
            if(target<candidates[i])break;
            temp.push_back(candidates[i]);
            comb2(candidates,target-candidates[i],ans,temp,i+1);
            temp.pop_back();
        }
        
       
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>> ans;
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        comb2(candidates,target,ans,temp,0);
        return ans;
    }
};