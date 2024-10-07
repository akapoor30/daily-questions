class Solution {
public:
    int minLength(string s) {
        if(s.size()==1)return 1;
        stack<char> st;
       
      
        int i=0;
        
        
        while(i<s.size()){
            
           
            if(!st.empty() && ((st.top()=='A' && s[i]=='B' )||(st.top()=='C' && s[i]=='D'))){
                st.pop();
                
                
                
            }
            else{
                st.push(s[i]);
                
            }
            i++;
        }
        return st.size();
    }
};