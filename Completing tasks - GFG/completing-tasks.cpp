//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>

using namespace std;



// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    pair<vector<int>, vector<int>> findTasks(int *arr, int m, int n) {
        // code here
        
        int hash[n+1] ={0};
        int flag=0;
        vector<int> tanya,manya;
        
        for(int i=0; i<m; i++)
        {
            hash[arr[i]] = 1;
        }
        
        for(int i=1; i<=n; i++)
        {
            if(hash[i] == 1)
                continue;
                
            if(flag == 0)
            {
                tanya.push_back(i);
                flag=1;
            }
            
            else if(flag == 1)
            {
                manya.push_back(i);
                flag=0;
            }
            
        }
        
        return {tanya,manya};
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) {
            cin >> arr[i];
        }
        Solution obj;
        auto ans = obj.findTasks(arr, m, n);
        for (auto x: ans.first) {
            cout << x << " ";
        }
        cout << "\n";
        for (auto x: ans.second) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends