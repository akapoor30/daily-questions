class Solution {
public:
    
    bool dfs(int node,vector<int> &vis,vector<int> &pathVis,vector<int> adj[],vector<int> &check){
        vis[node]=1;
        pathVis[node]=1;
        check[node]=0;
        
        for(auto i:adj[node]){
            if(!vis[i] ){
                if(dfs(i,vis,pathVis,adj,check))
                    return 1;
            }
            else if(pathVis[i])return 1;
        }
        check[node]=1;
        pathVis[node]=0;
        return 0;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
       
        int n=graph.size();
        int m=graph[0].size();
         vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[i].push_back(graph[i][j]);
            }
        }
        vector<int> vis(n,0);
        vector<int> pathvis(n,0);
        vector<int> check(n,0);
        for(int i=0;i<n;i++)
             if(!vis[i] ){
                    dfs(i,vis,pathvis,adj,check);
                  
                }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(check[i])ans.push_back(i);
        }
        return ans;
    }
};