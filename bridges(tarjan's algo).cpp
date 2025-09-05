class Solution {
public:
    void dfs(int node,int par,vector<vector<int>>& adj,vector<int>& vis,vector<int>&tin,vector<int>&low,int &time,vector<vector<int>>&bridges){
        time++;
        vis[node]=1;
        tin[node]=time,low[node]=time;
        for(auto x:adj[node]){
            if(x==par)continue;
            if(!vis[x]){
                dfs(x,node,adj,vis,tin,low,time,bridges);
                low[node]=min(low[node],low[x]);
                if(low[x]>tin[node]){
                    bridges.push_back({x,node});
                }
            }else{
                low[node]=min(low[node],low[x]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();++i){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> tin(n,0),low(n,0);
        int time=0;
        vector<int> vis(n,0);
        vector<vector<int>> bridges;
        dfs(0,-1,adj,vis,tin,low,time,bridges);
        return bridges;
    }
};
