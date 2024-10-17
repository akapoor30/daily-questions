class Solution {
public:
    int maximumSwap(int num) {
        string s=to_string(num);
        string s1=s;
        
        for(int i=0;i<s1.size();i++){
            for(int j=i+1;j<s1.size();j++){
                swap(s1[i],s1[j]);
                if(num<stoi(s1)){
                    num=stoi(s1);
                    
                }
                s1=s;
            }
            
        }
        return num;
    }
};