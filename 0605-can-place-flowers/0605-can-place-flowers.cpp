class Solution {
public:
    bool canPlaceFlowers(vector<int>& a, int n) {
        
        if(a.size()==1){
            if(a[0]==0 && (n==1||n==0))return 1;
            else if(a[0]==1 && n==0)return 1;
            else return 0;
        }
        
        for(int i=0;i<a.size();i++){
            if(i==0){
                if(a[i]==0 && a[i+1]==0  ){
                    n--;
                    a[i]=1;
                }
            }
            else if(i==a.size()-1){
                if(a[i]==0 && a[i-1]==0  ){
                    n--;
                    a[i]=1;
                }
            }
            else {
                if(a[i]==0 && a[i+1]==0 && a[i-1]==0  ){
                    n--;
                    a[i]=1;
                }
            }
        }
        cout<<n;
        if(n>0)return 0;
        return 1;
    }
};