//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        int ans = -1;
        vector<vector<int>> mat(n, vector<int>(m,0));
        
        mat[x-1][y-1] = 1;
        
        queue<pair<pair<int,int>,int>> q;
        
        q.push({{x-1,y-1},0});
        
        
        int delrow[4] = {1,0,0,-1};
        int delcol[4] = {0,1,-1,0};
        
        while(!q.empty())
        {
            
            auto t = q.front();
            q.pop();
            int row = t.first.first;
            int col = t.first.second;
            int tim = t.second;
            
            ans = max(ans,tim);
            
            for(int i=0; i<4; i++)
            {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >=0 and ncol>=0 and nrow<n and ncol<m and mat[nrow][ncol]==0)
                {
                    mat[nrow][ncol] = 1;
                    q.push({{nrow,ncol},tim+1});
                }
            }
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends