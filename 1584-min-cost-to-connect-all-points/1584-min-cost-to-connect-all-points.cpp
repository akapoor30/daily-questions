class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int op=0;
        vector<int> visited(n,false);
        vector<int> dist(n,INT_MAX);
        dist[0]=0;
        
        for(int i=0;i<n;i++)
        {
             int minDist=INT_MAX;
             int point=-1;
           for(int j=0;j<n;j++)
           {
               //check minimum dist
               if(dist[j]<minDist and !visited[j])
               {
                   minDist=dist[j];
                   point=j;
               }
           }
               visited[point]=true;
               op+=minDist;
               for(int k=0;k<n;k++)
               {
                   int d=abs(points[k][0]-points[point][0])+abs(points[k][1]-points[point][1]);
                   if(!visited[k] and dist[k]>d)
                   {
                       dist[k]=d;
                   }
               }
           
          
        }
        return op;
    }
};

