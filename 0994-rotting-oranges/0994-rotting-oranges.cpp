class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        queue<pair<int,pair<int,int>>> q;
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({0,{i,j}});
                    vis[i][j] = 1;
                }
            }
        }
        
        vector<int> delrow = {0,1,-1,0};
        vector<int> delcol = {1,0,0,-1};
        
        
        while(!q.empty())
        {
            
            auto t = q.front();
            q.pop();
            
            int time = t.first;
            
            int row = t.second.first;
            int col = t.second.second;
            
            grid[row][col] = 2;
            
            ans = max(time,ans);
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol] == 1 and !vis[nrow][ncol])
                {
                    vis[nrow][ncol] = 1;
                    q.push({time+1,{nrow,ncol}});
                }
                
            }
            
        }
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                {
                    return -1;
                }
            }
        }
        
        return ans;
        
    }
};