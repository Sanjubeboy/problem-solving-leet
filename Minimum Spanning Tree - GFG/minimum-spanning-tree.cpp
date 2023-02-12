//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        
        vector<int> vis(V,0);
        
        priority_queue< pair<int,pair<int,int>> , vector< pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>>> q;
        
        q.push({0,{0,-1}});
        int sum=0;
        
        while(!q.empty())
        {
            
            auto t=q.top();
            int wt=t.first;
            int u=t.second.first;
            int v=t.second.second;
            q.pop();
            
            if(vis[u]) continue;
            
            if(!vis[u] )
            {
                vis[u]=1;
                sum+=wt;
            }
            
            for(auto it: adj[u])
            {
                int wit=it[1];
                int node=it[0];
                q.push({wit,{node,u}});
                
            }
            
            
            
        }
        
        return sum;
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends