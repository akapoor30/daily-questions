class Solution {
public:
    
        int largestRectangleArea(vector<int>& arr) {
        
        int n=arr.size();
        stack<int> s;
        int leftind[n], rightind[n];
        
        for(int i=0;i<n;i++){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            
            if(s.empty())leftind[i]=0;
            else leftind[i]=s.top()+1;
            s.push(i);
        }
        while(!s.empty()){
                s.pop();
            }
        
        for(int i=n-1;i>=0;i--){
            while(!s.empty() && arr[s.top()]>=arr[i]){
                s.pop();
            }
            
            if(s.empty())rightind[i]=n-1;
            else rightind[i]=s.top()-1;
            s.push(i);
        }
        
        int maxi=0;
        
        for(int i=0;i<n;i++){
            maxi=max(maxi,(rightind[i]-leftind[i]+1)*arr[i]);
        }
        
        return maxi;
        
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        int ans=0;
        vector<int> histo(m,0);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1')histo[j]++;
                else histo[j]=0;
            }
             int area= largestRectangleArea(histo);
            ans=max(ans,area);
        }
        return ans;
    }
};