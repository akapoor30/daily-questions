class Solution {
public:
    bool check(string &s1,string &s2){
        int i=0,j=0;
        
        if(s1.size()!=s2.size()+1)return false;
        
        
        
        while(i<s1.size() ){
            if(s1[i]==s2[j]){
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
    
     static bool comp(string &s1,string &s2){
        return s1.size()<s2.size();
    }
    
    
    int longestStrChain(vector<string>& words) {
        
        int n= words.size();
        int maxi=1;
        
        vector<int> dp(n,1);
        sort(words.begin(),words.end(),comp);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[i],words[j]) && dp[i] < 1+dp[j]){
                    dp[i]=1+dp[j];
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
            }
        }
        return maxi;
    }
};