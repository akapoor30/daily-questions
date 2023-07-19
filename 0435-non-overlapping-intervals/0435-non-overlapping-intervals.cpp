bool comp(vector<int> &a,vector<int> &b) {
	return a[1]<b[1];
}
class Solution {
public:

    
    
    int eraseOverlapIntervals(vector<vector<int>>& a) {
        int count=0;
        sort(a.begin(),a.end(),comp);
        // f(a,count,0,-1000);
        int prev=a[0][1];
        for(int i=1;i<a.size();i++){
            if(prev>a[i][0])count++;
            else prev=a[i][1];
        }
        return count;
    }
};