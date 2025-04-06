class Solution {
public:
    int n;
    vector<int> sNums;
    vector<vector<int>> dp;
    int rec(int i, int prev) {
        if(i >= n) return 0;
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        int take = 0;
        if(prev == -1 || sNums[i] % sNums[prev] == 0)
            take = 1 + rec(i+1, i);
        int notTake = rec(i+1, prev);
        int res = (take > notTake) ? take : notTake;
        dp[i][prev+1] = res;
        return res;
    }
    void reconstruct(int i, int prev, vector<int>& subset) {
        if(i >= n) return;
        int take = 0;
        if(prev == -1 || sNums[i] % sNums[prev] == 0)
            take = 1 + rec(i+1, i);
        int notTake = rec(i+1, prev);
        if(prev == -1 || sNums[i] % sNums[prev] == 0) {
            if(take >= notTake) {
                subset.push_back(sNums[i]);
                reconstruct(i+1, i, subset);
                return;
            }
        }
        reconstruct(i+1, prev, subset);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.empty()) return {};
        sNums = nums;
        sort(sNums.begin(), sNums.end());
        n = sNums.size();
        dp.assign(n, vector<int>(n+1, -1));
        rec(0, -1);
        vector<int> ans;
        reconstruct(0, -1, ans);
        return ans;
    }
};
