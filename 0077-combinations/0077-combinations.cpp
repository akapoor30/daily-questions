class Solution {
public:
    
    void f(int ind,int n,int k,vector<vector<int>> &ans,vector<int> &tmp){
        if(tmp.size()==k){
            ans.push_back(tmp);
            return;
        }
        
        for(int i=ind;i<=n;i++){
            tmp.push_back(i);
            f(i+1,n,k,ans,tmp);
            tmp.pop_back();
        }
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        f(1,n,k,ans,tmp);
        return ans;
    }
};