class Solution {
public:
    int minDeletions(string s) {
        vector<int> vec(26,0);
        
        for(int i=0;i<s.size();i++){
            int index=s[i]-'a';
            vec[index]++;
            
            
        }
        int countD=0;
        
        priority_queue<int> p;
      
        
        for(int i=0;i<26;i++){
            if(vec[i]>0)
                p.push(vec[i]);
           
        }
        
        int current;
        
        while(!p.empty() && p.top()>0){
            
            current=p.top(); //3 3 2
            //cuurent=3 //3 2 //current=2 //3 2 2
            //cuurent=3 //2 2
            p.pop();
            
            if(!p.empty() && p.top()==current){
                countD++;
                current--;
                p.push(current);
            }
        }
        return countD;
    }
};