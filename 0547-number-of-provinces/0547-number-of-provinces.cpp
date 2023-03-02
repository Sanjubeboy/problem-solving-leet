class Solution {
    
private:
    
    void dfs(int node, vector<vector<int>> &isConnected, vector<int> &vis)
    {
        
        vis[node] = 1;
        
        int n = isConnected.size();
        
        for(int i=0; i<n; i++)
        {
            if(!vis[i+1] and isConnected[node-1][i])
            {
                dfs(i+1,isConnected,vis);
            }
        }
        
    }
    
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        
        int n = isConnected.size();
        vector<int> vis(n+1,0);
        
        int ans = 0;
        
        for(int i=1; i<=n; i++)
        {
            if(!vis[i])
            {
                dfs(i,isConnected,vis);
                ans++;
            }
        }
        
        
        return ans;
        
    }
};