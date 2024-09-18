class Solution {
public:
    
    bool f(int i,int j, string s1, string s2,vector<vector<int>> &dp){
        if(i==0 && j==0)return 1;
        if(i==0 && j>0)return 0;
        if(i>0 && j==0){
            for(int ii=1;ii<=i;ii++){
                if(s1[ii-1]!='*')return 0;
            }
            return 1;
        }
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s1[i-1]==s2[j-1] || s1[i-1]=='?') return dp[i][j]=f(i-1,j-1,s1,s2,dp);
        
        if(s1[i-1]=='*'){
            return dp[i][j]=f(i-1,j,s1,s2,dp) | f(i,j-1,s1,s2,dp);
        }
        
        return dp[i][j]=0;
    }
    
    
    bool isMatch(string s, string t) {
        int m=s.size(),n=t.size();
        string s1 = t, s2 = s;
        
        
        
        vector<vector<bool>> dp(n+1,vector<bool>(m+1,0));
        vector<bool> prev(m+1,0),curr(m+1,0); 
        prev[0]=true;
        
        for(int j=1;j<=m;j++){
            prev[j]=false;
        }
        
//         for(int i=0;i<=n;i++){
//             bool flag=true;
//             for(int ii=1;ii<=i;ii++){
                
//                 if(s1[ii-1]!='*'){
//                     flag=false;
//                     break;
//                 }
          
//             }
            
//             curr[0]=flag;
//         }
        
        for(int i=1;i<=n;i++){
             bool flag=true;
            for(int ii=1;ii<=i;ii++){
                
                if(s1[ii-1]!='*'){
                    flag=false;
                    break;
                }
          
            }
            
            curr[0]=flag;
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1] || s1[i-1]=='?')  curr[j]=prev[j-1];
        
                else if(s1[i-1]=='*'){
                     curr[j]=prev[j] | curr[j-1];
                }

                else curr[j]=0;
            }
            
            prev=curr;
        }
        
        
        
        return prev[m];
    }
};