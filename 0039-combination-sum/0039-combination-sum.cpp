class Solution {
public:
    
    void comb1(vector<vector<int>> &ans,vector<int>& candidates, int target,vector<int> &temp,int ind){
        if(ind==candidates.size()){
            if(target==0){
                ans.push_back(temp);
                
            }
            return ;
        }
        
        if(target>=candidates[ind]){
            temp.push_back(candidates[ind]);
            comb1(ans,candidates,target-candidates[ind],temp,ind);
            temp.pop_back();
        }
         comb1(ans,candidates,target,temp,ind+1);
    }
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        comb1(ans,candidates,target,temp,0);
        
        return ans;
    }
};