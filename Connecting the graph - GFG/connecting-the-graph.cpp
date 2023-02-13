//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class disjointset{
    public:
    
    vector<int> parent, rank;
    
    
    disjointset(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        
    }
    
    
    int findpair(int node)
    {
        if(parent[node]==node)
            return node;
            
        return parent[node] = findpair(parent[node]);          //Path Compression
    }
    
    
    void unionbyrank(int u,int v)
    {
        int p=findpair(u);
        int q=findpair(v);
        
        if(p == q)
        {
            return;
        }
        
        else if(rank[p] == rank[q])
        {
            parent[p]=q;
            rank[q]++;
        }
        else if(rank[p] >rank[q])
        {
            parent[q]=p;
            
        }
        else
        {
            parent[p]=q;
        }
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edges) {
        // code here
        
        disjointset ds(n);
        int extras=0;
        
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            
            if(ds.findpair(u) == ds.findpair(v))
                extras++;
            
            else
                ds.unionbyrank(u,v);
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
            {
                cnt++;
            }
        }
        
        // cout<<cnt;
        // cout<<ds.extra;
        
        if(extras >= cnt-1)
        {
            return cnt-1;
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends