class Solution {
    long long solve(vector<vector<int>>& a, int i, int n,
                    vector<long long>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1)
            return dp[i];
        long long take = -1e9;
        long long nottake = solve(a, i + 1, n, dp);
        if (i < n) {
            take = a[i][0] + solve(a, i + a[i][1] + 1, n, dp);
        }
        return dp[i] = max(take, nottake);
    }

public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, -1);
        return solve(questions, 0, n, dp);
    }
};