class Solution {
    
    bool isPossible(vector<int>& dist, double hour,int mid){
        double h=0;
        
        for(int i=0;i<dist.size()-1;i++){
            h+=ceil(((double)dist[i])/mid);
            
        }
        
        h+=(double)(dist[dist.size()-1])/mid;
        if(hour>=h)
            return 1;
        
         return 0;
    }
    
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int s=1;
        int e=10000000,mid;
        
        int ans=-1;
        
        
        while(s<=e){
            mid=s+(e-s)/2;
            
            if(isPossible(dist,hour,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return ans;
    }
};