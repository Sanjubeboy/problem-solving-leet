//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:

    int n,m;
    
    vector<vector<int>> lab;
    
    void dfs(int i,int j,vector<vector<int>> &mat,int prevval,int label)
    {
        if(i<0 || j<0 || i>=n || j>=m || lab[i][j]&label)
            return;
        
        int currentval=mat[i][j];
        
        if(currentval>=prevval)
        {
            lab[i][j]=lab[i][j]|label;
            
            dfs(i+1,j,mat,currentval,label);
            dfs(i-1,j,mat,currentval,label);
            dfs(i,j-1,mat,currentval,label);
            dfs(i,j+1,mat,currentval,label);
            
        }
        
    }
    
    int water_flow(vector<vector<int>> &mat,int N,int M)
    {
    // Write your code here.
        n=N;
        m=M;
        
        int count=0;
        
        lab.resize(n,vector<int>(m,0));
        
        
        for(int i=0;i<n;i++)
        {
            dfs(i,0,mat,mat[i][0],1);
            dfs(i,M-1,mat,mat[i][M-1],2);
        }
        
        for(int j=0;j<m;j++)
        {
            dfs(0,j,mat,mat[0][j],1);
            dfs(N-1,j,mat,mat[N-1][j],2);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(lab[i][j]==3)
                {
                    count++;
                }
            }
        }
        
        return count;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends