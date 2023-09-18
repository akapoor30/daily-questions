class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> p;
        // int count=0;
        
        for(int i=0;i<mat.size();i++){
             int count=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1)
                    count++;
               
            }
            p.push({count,i});
            if(p.size()>k)
                p.pop();
            
            
        }
        
        vector<int> vec;
        
       while(p.size())
       {
           vec.push_back(p.top().second);
           p.pop();
       }
        
          reverse(vec.begin(),vec.end());
     return vec;   
    }
};