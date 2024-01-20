class Solution {
public:
    long long mod=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int> preSmall(n),postSmall(n);
        
        for(int i=0;i<n;i++){
            preSmall[i]=i;
            postSmall[i]=n-i-1;
            
        }
        stack<int> s1,s2;
        
        for(int i=0;i<n;i++){
            while(!s1.empty() && arr[s1.top()]>arr[i]){
                postSmall[s1.top()]=i-s1.top()-1;
                s1.pop();
            }
            s1.push(i);
        }
        for(int i=n-1;i>=0;i--){
            while(!s2.empty() && arr[s2.top()]>=arr[i]){
                preSmall[s2.top()]=s2.top()-i-1;
                s2.pop();
            }
            s2.push(i);
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans+=((arr[i])%mod*(postSmall[i]+1)%mod*(preSmall[i]+1)%mod)%mod;
            ans%=mod;
        }
        return ans;
    }
};