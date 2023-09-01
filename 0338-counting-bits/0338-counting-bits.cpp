class Solution {
public:
    vector<int> countBits(int n) {
        int count=0;
         vector<int> vec(n);
        vec.push_back(0);
        
        for(int i=1;i<=n;i++){
          if(i%2==0){
              vec[i]=vec[i/2];
          }
           else
               vec[i]=vec[i/2]+1;
        }
        return vec;
    }
};