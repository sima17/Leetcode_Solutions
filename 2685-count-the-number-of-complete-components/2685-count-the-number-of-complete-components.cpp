class Solution {
public:
    bool solve(int &node,vector<vector<int>>&adj,vector<bool>&vis,int &cNode){
        vis[node]=1;
        if(adj[node].size()!=cNode-1){
            return 0;
        }
        for(auto x:adj[node]){
            if(!vis[x]){
                return solve(x,adj,vis,cNode);
            }
        }
        return 1;
    }
    void dfs(int &node,vector<vector<int>>&adj,vector<bool>&vis,int &cNode){
        vis[node]=1;
        cNode++;
        for(int j=0;j<adj[node].size();j++){
            if(!vis[adj[node][j]]){
                dfs(adj[node][j],adj,vis,cNode);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(n,0);
        int ans=0;
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                int cNode=0;
                dfs(i,adj,vis,cNode);
                temp.push_back({i,cNode});
            }
        }
        vis.assign(n,0);
        for(auto x:temp){
            ans+=solve(x.first,adj,vis,x.second);
        }
        return ans;
    }
};