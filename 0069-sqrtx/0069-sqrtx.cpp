class Solution {
public:
    int mySqrt(int x) {
        int low=1,high=x;
        while(low<=high){
            long long int mid=high+(low-high)/2;
            long long int temp = mid*mid;
            if(temp<=x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return high;
    }
};