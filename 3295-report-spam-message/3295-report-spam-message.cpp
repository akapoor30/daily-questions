class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_map<string,int> mp;
        for(int i=0;i<bannedWords.size();i++){
            mp[bannedWords[i]]++;
        }
        int temp=0;
        for(int i=0;i<message.size();i++){
            if(mp.find(message[i])!=mp.end()){
                temp++;
            }
        }
        if(temp>=2)return 1;
        
        return 0;
    }
};