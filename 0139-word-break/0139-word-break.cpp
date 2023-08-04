class Solution {
private:
    int solve(string s,int idx,unordered_map<string,int>& mp,int *dp){
        
        if(idx==s.size()) return 1;
        if(dp[idx]!=-1) return dp[idx];
        string temp;
        for(int j=idx;j<s.size();j++){
            temp+=s[j];
            if(mp.find(temp)!=mp.end()){
                if(solve(s,j+1,mp,dp)) return dp[idx]=1;
            }
        }
        return dp[idx]=0;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
  vector<int> dp(s.size()+1, 0);
        unordered_map<string,int> mp;
        for(auto& idx:wordDict) mp[idx];
        
        dp[s.size()]=1;
        
        for(int i=s.size()-1;i>=0;i--){
        string temp="";
            for(int j=i;j<s.size();j++){
                temp+=s[j];
                if(mp.find(temp)!=mp.end()){
                    if(dp[j+1]==1)  dp[i]=1;
                }
            }
            
          // dp[i]=0;
        }
        
        return dp[0];
    }
};