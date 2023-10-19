class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1,s2;
        
        for(int i=0;i<s.size();i++){
            if(s1.size()<1 && s[i]=='#')
                continue;
            s1.push(s[i]);
            if(s1.top()=='#' && s1.size()>1){
                s1.pop();
                s1.pop();
                
            }
        }
        for(int i=0;i<t.size();i++){
            if(s2.size()<1 && t[i]=='#')
                continue;
            s2.push(t[i]);
            if(s2.top()=='#' && s2.size()>1){
                s2.pop();
                s2.pop();
                
            }
        }
        // cout<<s1.top()<<" "<<s2.top(); 
        if(s1==s2)
            return 1;
        return 0;
    }
};