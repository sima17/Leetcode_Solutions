class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<bool> attendance(n * n + 1, false);
        int duplicate = -1;

        // Mark occurrences in attendance array
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (attendance[grid[i][j]]) {
                    duplicate = grid[i][j];
                } else {
                    attendance[grid[i][j]] = true;
                }
            }
        }

        // Find the missing number
        for (int i = 1; i <= n * n; i++) {
            if (!attendance[i]) return {duplicate, i};
        }
        return {};
    }
};