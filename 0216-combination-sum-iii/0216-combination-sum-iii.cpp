class Solution {
public:
    
    void f(int k,int n,vector<vector<int>> &ans, vector<int> &tmp,int index){
        if(tmp.size()==k){
            if(n==0){
                ans.push_back(tmp);
            }
            return ;
        }
        if(index>9)return;
        if(index<=n){
            tmp.push_back(index);
            f(k,n-index,ans,tmp,index+1);
            tmp.pop_back();
        }
        f(k,n,ans,tmp,index+1);
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        f(k,n,ans,tmp,1);
        return ans;
    }
};