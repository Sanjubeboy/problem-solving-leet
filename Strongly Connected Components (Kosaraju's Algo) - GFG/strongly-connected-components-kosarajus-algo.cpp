//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfs1(int node, vector<int> adj[], stack<int> &st, vector<int> &vis)
	{
	    
	    vis[node] = 1;
	    
	    for(auto it: adj[node])
	    {
	        if(!vis[it])
	        {
	            dfs1(it,adj,st,vis);
	        }
	    }
	    st.push(node);
	    
	}
	
	void dfs2(int node, vector<int> adjt[], vector<int> &vis1)
	{
	    vis1[node] = 1;
	    
	    for(auto it: adjt[node])
	    {
	        if(!vis1[it])
	            dfs2(it,adjt,vis1);
	    }
	}
	
    int kosaraju(int V, vector<vector<int>>& mat)
    {
        
        
        
        
        vector<int> adj[V];
        vector<int> adjt[V];
        
        
        for(int i=0; i<V; i++)
        {
            for(auto it: mat[i])
            {
                
                    adj[i].push_back(it);
                    adjt[it].push_back(i);
                
                // cout<<it<<" ";
            }
            // cout<<endl;
        }
        
        // for(int i=0; i<V; i++)
        // {
        //     for(auto it: adj[i])
        //     {
        //         cout<<it<<" ";
        //     }
        //     cout<<endl;
        // }
        
        stack<int> st;
        vector<int> vis(V,0);
        
        for(int i=0; i<V; i++)
        {
            if(!vis[i])
                dfs1(i,adj,st,vis);
        }
        
        
        
        vector<int> vis1(V,0);
        int cnt = 0;
        
        while(!st.empty())
        {
            int t = st.top();
            st.pop();
            
            if(!vis1[t])
            {
                dfs2(t,adjt,vis1);
                cnt++;
            }
        }
        
        return cnt;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends