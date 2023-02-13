//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class disjointset{
    
    
public:
    vector<int> parent,rank;
    disjointset(int n)
    {
        parent.resize(n+1);
        rank.resize(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            parent[i]=i;
            
        }
    }
    
    int findpair(int node)                                             //disjoint set datastructure
    {
        if(parent[node] == node)
            return node;
            
        return parent[node] = findpair(parent[node]);
    }
    
    void unionbyrank(int u,int v)
    {
        int up_u=findpair(u);
        int up_v=findpair(v);
        
        if(up_v == up_u)
        {
            return;
        }
        
        else if(rank[up_u] == rank[up_v])
        {
            parent[up_u]=up_v;
            rank[up_v]++;
            
        }
        else if(rank[up_u] < rank[up_v])
        {
            parent[up_u]=up_v;
        }        
        else
        {
            parent[up_v]=up_u;
        }
    }
    
    
    
    
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        
        disjointset ds(V);
        vector<pair<int,int>> edges;
        
        for(int i=0;i<V;i++)
        {
            for(int j=0;j<V;j++)
            {
                if(adj[i][j]==1)
                {
                    edges.push_back({i+1,j+1});
                }
            }
        }
        
        for(auto it:edges)
        {
            int u=it.first;
            int v=it.second;
            ds.unionbyrank(u,v);
        }
        
        int ans=0;
        
        for(int i=1;i<=V;i++)
        {
            if(ds.parent[i] == i)
                ans++;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends
