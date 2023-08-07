class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0,e=(matrix.size()*matrix[0].size())-1;
        
        int m;
        
        while(s<=e){
            int m=s+(e-s)/2;
            int midMatrix=matrix[m/matrix[0].size()][m%matrix[0].size()];
                if(midMatrix==target)
                    return 1;
            else if(midMatrix>target)
                e=m-1;
            else
                s=m+1;
        }
        return 0;
    }
};