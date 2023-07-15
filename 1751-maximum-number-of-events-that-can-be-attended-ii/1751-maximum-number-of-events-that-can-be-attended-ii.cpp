class Solution {
public:
    int f(vector<vector<int>>& events, int k, int index, int ft, vector<vector<int>>& dp) {
        if (index == events.size() || k == 0) {
            return 0;
        }
        
        int st = events[index][0];
        if (dp[index][k] != -1) {
            return dp[index][k];
        }
        
        // Find the next non-overlapping event
        int i;
        for (i = index + 1; i < events.size(); i++) {
            if (events[i][0] > events[index][1]) {
                break;
            }
        }
        
        int nottake = f(events, k, index + 1, ft, dp);
        int take = events[index][2] + f(events, k - 1, i, ft, dp);
        
        return dp[index][k] = max(take, nottake);
    }
    
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp(events.size() + 1, vector<int>(k + 1, -1));
        return f(events, k, 0, -1000, dp);
    }
};
