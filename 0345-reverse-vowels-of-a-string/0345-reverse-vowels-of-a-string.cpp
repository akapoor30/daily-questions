class Solution {
public:
    string reverseVowels(string s) {
        string temp="";
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ){
                temp+=s[i];
             
            }
        }
        int k=0;
        reverse(temp.begin(),temp.end());
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' ||s[i]=='A' ||s[i]=='E' ||s[i]=='I' ||s[i]=='O' ||s[i]=='U' ){
                s[i]=temp[k++];
                
            }
            cout<<s[i]<<" ";
        }
        return s;
    }
};