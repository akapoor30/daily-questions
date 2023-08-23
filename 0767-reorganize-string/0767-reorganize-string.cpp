class Solution {
public:
    string reorganizeString(string s) {
       unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            if(mp[s[i]]>(s.size()+1)/2)
                return "";
        }
        
        priority_queue<pair<int,char>> pq;
        
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        string ans="";
        while(!pq.empty()){
            auto[cnt1,ch1]=pq.top();
            pq.pop();
            
            ans+=ch1;
            cnt1--;
            if(pq.empty())
                return ans;
            cout<<" 1 "<<cnt1<<" "<<endl;
            auto[cnt2,ch2]=pq.top();
            // s+=ch1;
            // cnt1--;
            ans+=ch2;
            cnt2--;
             pq.pop();
            if(cnt1>0)
               pq.push({cnt1,ch1});
             if(cnt2>0)
               pq.push({cnt2,ch2});
            
        }
        
        return ans;
    }
};