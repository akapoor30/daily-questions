class Solution {
public:
    
    bool isPalin(string s,int st,int e){
        while(st<=e){
            if(s[st]!=s[e]){
                return 0;
            }
            st++;
            e--;
        }
        return 1;
    }
    
    void f(int ind,string s,vector<vector<string>> &ans,vector<string> &temp){
        if(ind==s.size()){
            ans.push_back(temp);
            return ;
        }
        
        for(int i=ind;i<s.size();i++){
            if(isPalin(s,ind,i)){
                temp.push_back(s.substr(ind,i-ind+1));
                f(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        
        f(0,s,ans,temp);
        
        return ans;
    }
};