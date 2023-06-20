//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    
    vector<int> deli = {1,0,0,-1,1,-1,1,-1};
    vector<int> delj = {0,1,-1,0,1,1, -1, -1};
    
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &vis, int n, int m)
    {
        vis[i][j] = 1;
        
        for(int k=0; k<8; k++)
        {
            int ni = i + deli[k];
            int nj = j + delj[k];
            
            if(ni>=0 and ni<n and nj>=0 and nj<m and !vis[ni][nj] and grid[ni][nj]== '1')
            {
                dfs(ni, nj, grid, vis, n, m);
            }
        }
        
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        
        vector<vector<int>> vis(n, vector<int> (m, 0));
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(!vis[i][j] and grid[i][j] == '1')
                {
                    dfs(i, j, grid, vis, n, m);
                    ans++;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends