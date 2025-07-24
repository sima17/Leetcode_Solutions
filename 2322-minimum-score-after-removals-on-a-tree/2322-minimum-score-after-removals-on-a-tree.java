class Solution {

    public int minimumScore(int[] nums, int[][] edges) {
        int n = nums.length;

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());
        for (int[] e : edges) {
            adj.get(e[0]).add(e[1]);
            adj.get(e[1]).add(e[0]);
        }

        int[] sum = new int[n];
        int[] in = new int[n];
        int[] out = new int[n];
        int[] time = {0};

        dfs(0, -1, nums, adj, sum, in, out, time);

        int result = Integer.MAX_VALUE;

        for (int u = 1; u < n; u++) {
            for (int v = u + 1; v < n; v++) {

                if (in[v] > in[u] && in[v] < out[u]) {
                    int a = sum[0] ^ sum[u];        
                    int b = sum[u] ^ sum[v];       
                    int c = sum[v];               
                    result = Math.min(result, calc(a, b, c));

                } else if (in[u] > in[v] && in[u] < out[v]) {
                    int a = sum[0] ^ sum[v];
                    int b = sum[v] ^ sum[u];
                    int c = sum[u];
                    result = Math.min(result, calc(a, b, c));

                } else {
                    int a = sum[0] ^ sum[u] ^ sum[v];
                    int b = sum[u];
                    int c = sum[v];
                    result = Math.min(result, calc(a, b, c));
                }
            }
        }

        return result;
    }

    private int calc(int a, int b, int c) {
        return Math.max(a, Math.max(b, c)) - Math.min(a, Math.min(b, c));
    }

    
    private void dfs(
        int node,
        int parent,
        int[] nums,
        List<List<Integer>> adj,
        int[] sum,
        int[] in,
        int[] out,
        int[] time
    ) {
        in[node] = time[0]++;
        sum[node] = nums[node];

        for (int neighbor : adj.get(node)) {
            if (neighbor == parent) continue;
            dfs(neighbor, node, nums, adj, sum, in, out, time);
            sum[node] ^= sum[neighbor]; 
        }

        out[node] = time[0];
    }
}