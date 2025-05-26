class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        
        // Build the graph and indegree list
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }

        // DP table to store color counts for each node
        vector<vector<int>> dp(n, vector<int>(26, 0));
        queue<int> q;

        // Initialize queue with nodes having zero indegree
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
            dp[i][colors[i] - 'a'] = 1; // Start with own color
        }

        int processed = 0;
        int maxColorValue = 0;

        // Kahn's algorithm + color DP
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            processed++;

            for (int neighbor : graph[node]) {
                for (int c = 0; c < 26; ++c) {
                    int extra = (colors[neighbor] - 'a' == c) ? 1 : 0;
                    dp[neighbor][c] = max(dp[neighbor][c], dp[node][c] + extra);
                }

                // Decrease indegree and push if it's 0
                if (--indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }

            // Update max color value at current node
            maxColorValue = max(maxColorValue, *max_element(dp[node].begin(), dp[node].end()));
        }

        // If not all nodes were processed, there's a cycle
        return (processed == n) ? maxColorValue : -1;
    }
};