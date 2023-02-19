class Solution {
public:
    
    int timer = 1;
    void dfs(int node, int parent, vector<int> &tin, vector<int> &vis, vector<int> &low, vector<vector<int>> &ans, vector<int> adj[])
    {
        
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        
        for(auto it: adj[node])
        {
            
            if(it == parent)
                continue;
            
            if(!vis[it])
            {
                dfs(it, node, tin, vis, low, ans, adj);
                low[node] = min(low[node], low[it]);
                
                if(low[it] > tin[node])
                {
                    ans.push_back({node,it});
                }
            }
            
            else
            {
                low[node] = min(low[it], low[node]);  
            }
            
        }
        
    }
    
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int> adj[n];
        
        for(auto it: connections)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(n,0);
        vector<int> tin(n,0);
        vector<int> low(n);
        
        vector<vector<int>> ans;
        
        dfs(0, -1, tin, vis, low, ans, adj);
        
        
        return ans;
        
        
        
    }
};