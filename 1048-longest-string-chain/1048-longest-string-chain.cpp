class Solution {
public:
    
    bool check(string &s1 , string &s2){
        if(s1.size()!=s2.size()+1)return 0;
        
        int i=0,j=0;
        while(i<s1.size()){
            if(j < s2.size() && s1[i]==s2[j]){
                i++;
                j++;
                
            }
            else{
                i++;
                
            }
        }
        
        if(i==s1.size() && j==s2.size())return 1;
        
        return 0;
    }
    static  bool comp(string &s1 , string &s2){
         return s1.size()<s2.size();
     }
    
    int longestStrChain(vector<string>& words) {
       int maxi=1;
         sort(words.begin(), words.end(),comp);

        vector<int> dp(words.size(),1);
        for(int i=0;i<words.size();i++){
            for(int prev=0;prev<i;prev++){
                if(check(words[i],words[prev]) && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                }
            }
            if(dp[i]>maxi)maxi=dp[i];
        }
        
        return maxi;
    }
};