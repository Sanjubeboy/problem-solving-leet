class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        queue<pair<int, pair<int,int>>> q;
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2){
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
                    
            }
        }
        
        vector<int> deli = {1,0,0,-1};
        vector<int> delj = {0,1,-1,0};
        
        
        while(!q.empty())
        {
            auto t = q.front();
            int i = t.second.first;
            int j = t.second.second;
            int time = t.first;
            
            ans = max(ans, time);
            q.pop();
            
            for(int k=0; k<4; k++)
            {
                int newi = i + deli[k];
                int newj = j + delj[k];
                
                if(newi>=0 and newi<n and newj>=0 and newj<m and !vis[newi][newj] and grid[newi][newj] == 1)
                {
                    q.push({time+1,{newi, newj}});
                    vis[newi][newj] = 1;
                }
            }
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(vis[i][j] == 0 and grid[i][j] == 1)
                    return -1;
            }
        }
        
        return ans;
    }
};