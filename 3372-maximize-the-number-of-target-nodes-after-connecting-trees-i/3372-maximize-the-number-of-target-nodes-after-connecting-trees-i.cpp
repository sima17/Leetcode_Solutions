class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> tree1(n), tree2(m);
        for (auto& e : edges1) {
            tree1[e[0]].push_back(e[1]);
            tree1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            tree2[e[0]].push_back(e[1]);
            tree2[e[1]].push_back(e[0]);
        }

        // Step 1: Precompute max number of reachable nodes in tree2 within distance d (0 <= d <= k)
        vector<int> max_reachable_tree2(k + 1, 0);

        for (int i = 0; i < m; ++i) {
            vector<int> dist(m, -1);
            queue<int> q;
            q.push(i);
            dist[i] = 0;
            int reachable = 0;
            vector<int> cnt(k + 1, 0);
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (dist[u] <= k) {
                    cnt[dist[u]]++;
                }
                if (dist[u] >= k) continue;
                for (int v : tree2[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            int sum = 0;
            for (int d = 0; d <= k; ++d) {
                sum += cnt[d];
                max_reachable_tree2[d] = max(max_reachable_tree2[d], sum);
            }
        }

        // Step 2: For each node in tree1, count reachable nodes within distance k and combine with tree2
        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            vector<int> dist(n, -1);
            queue<int> q;
            q.push(i);
            dist[i] = 0;
            int reachable = 0;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                if (dist[u] <= k) reachable++;
                if (dist[u] >= k) continue;
                for (int v : tree1[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }

            int from_tree2 = (k >= 1) ? max_reachable_tree2[k - 1] : 0;
            res[i] = reachable + from_tree2;
        }

        return res;
    }
};