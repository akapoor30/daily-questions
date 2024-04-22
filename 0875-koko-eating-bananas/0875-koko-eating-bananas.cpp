class Solution {
public:
    
    long long int func(vector<int>& piles,int hours){
        long long int totHour=0;
        
        for(int i=0;i<piles.size();i++){
            totHour+=ceil((double)piles[i]/(double)hours);
             
        }
        return totHour;
        
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi=INT_MIN;
        for(int i=0;i<piles.size();i++){
            maxi=max(maxi,piles[i]);
        }
        
        
        int low=1,high=maxi,ans=1;;
        
        while(low<=high){
           long long int mid=(low+high)/2;
           long long int temp=func(piles,mid);
            if(temp<=h){
                // ans=mid;
                high=mid-1;
            }
            else{
              low=mid+1;  
            }
        }
        
        return low;
    }
};