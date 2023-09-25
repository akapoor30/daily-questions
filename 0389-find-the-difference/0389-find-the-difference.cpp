class Solution {
public:
    char findTheDifference(string s, string t) {
        char x;
       
        x=accumulate(t.begin(),t.end(),0)-accumulate(s.begin(),s.end(),0);
        return x;
    }
};