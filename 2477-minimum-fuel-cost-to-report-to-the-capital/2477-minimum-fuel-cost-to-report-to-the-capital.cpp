class Solution {
public:
    
    long long int ans=0;
    
    int dfs(int node,vector<int> adj[],int k,vector<int> &vis)
    {
        vis[node]=1;
        int cnt=1;
        
        for(auto it: adj[node])
        {
            if(!vis[it])
            {
                cnt+=dfs(it,adj,k,vis);
            }
        }
        
        if(node!=0)
        {
            ans+=(cnt+k-1)/k;
        }
        
        return cnt;
        
        
        
        
    }
    
    
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        
        int n=roads.size()+1;
        vector<int> vis(n,0);
        vector<int> adj[n+1];
        
        for(auto it: roads)
        {
            int u=it[0];
            int v=it[1];
            // int wt=it[2];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
            
            
        }
        
        
        dfs(0,adj,seats,vis);
        return ans;
        
    }
};