//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class disjointset{
    public:
    
        vector<int> size, parent;
        
        disjointset(int n)
        {
            size.resize(n+1,0);
            parent.resize(n+1,0);
            
            for(int i=0;i<n+1;i++)
            {
                parent[i] = i;
            }
            
        }
        
        
        int findpar(int node)
        {
            if(parent[node] == node)
                return node;
                
            return parent[node] = findpar(parent[node]);
        }
        
        void unionbysize(int u,int v)
        {
            int up = findpar(u);
            int vp = findpar(v);
            
            if(up == vp)
                return;
                
            if(size[up] > size[vp])
            {
                parent[vp] = up;
                size[up]+=size[vp];
            }
            
            else
            {
                parent[up] = vp;
                size[vp] += size[up];
            }
            
        }
};

class Solution {
  public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        // Code here
        
        int maxrow = -1;
        int maxcol = -1;
        
        for(auto it: stones)
        {
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol, it[1]);
        }
        
        disjointset ds(maxrow + maxcol + 1);
        
        unordered_map<int,int> mp;
        
        for(auto it: stones)
        {
            int row = it[0];
            int col = maxrow + it[1] + 1;
            
            ds.unionbysize(row,col);
            mp[row] = 1;
            mp[col] = 1;
            
        }
        
        int cnt = 0;
        
        for(auto it: mp)
        {
            if(ds.parent[it.first] == it.first)
                cnt++;
        }
        
        return n - cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> adj;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < 2; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;

        cout << obj.maxRemove(adj, n) << "\n";
    }
}
// } Driver Code Ends