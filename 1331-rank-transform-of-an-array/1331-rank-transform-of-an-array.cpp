class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> vec=arr;
        sort(vec.begin(),vec.end());
        
        unordered_map<int,int> mp;
        
        int i=0;
        
        int rank=1;
        
        while(i<arr.size()){
            if(i==0){
                mp[vec[0]]=1;
            }
            else{
                if(vec[i]==vec[i-1]){
                    mp[vec[i]]=rank;
                }
                else{
                    rank++;
                    mp[vec[i]]=rank;
                }
            }
            i++;
        }
        
        
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i])!=mp.end()){
                arr[i]=mp[arr[i]];
            }
        }
        
        return arr;
    }
};