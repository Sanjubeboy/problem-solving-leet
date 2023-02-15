//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class disjointset{
    
public:
    vector<int> parent,rank;
    
    disjointset(int n)
    {
        parent.resize(n);
        rank.resize(n,0);
        
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
    }
    
    int findpair(int node)
    {
        if(parent[node] == node)
            return node;
        
        return parent[node] = findpair(parent[node]);
    }
    
    void unionbyrank(int u,int v)
    {
        int up = findpair(u);
        int vp = findpair(v);
        
        if(up == vp)
            return;
        
        if(rank[up] == rank[vp])
        {
            parent[up] = vp;
            rank[vp]++;
        }
        
        else if(rank[up] < rank[vp])
        {
            parent[up] = vp;
        }
        
        else 
        {
            parent[vp] = up;
        }
    }
};



class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        // code here
        
        disjointset ds(accounts.size());
        unordered_map<string,int> mailnode;
        
        for(int i=0; i<accounts.size(); i++)
        {
            for(int j=1; j<accounts[i].size(); j++)
            {
                
                string mail = accounts[i][j];
                
                if(mailnode.find(mail) != mailnode.end())
                {
                    ds.unionbyrank(i , mailnode[mail]);
                }
                
                mailnode[mail] = i;
                
            }
        }
        
        
        vector<string> mergemail[accounts.size()];
        
        for(auto it:mailnode)
        {
            string id = it.first;
            int node = ds.findpair(it.second);
            
            mergemail[node].push_back(id);
        }
        
        
        vector<vector<string>> ans;
        
        for(int i=0; i<accounts.size(); i++)
        {
            if(mergemail[i].size() == 0) continue;
            
            vector<string> temp;
            sort(mergemail[i].begin(),  mergemail[i].end());
            
            temp.push_back(accounts[i][0]);
            
            // temp.push_back(mergemail[i]);
            
            for(auto it: mergemail[i])
            {
                temp.push_back(it);
            }
            
            ans.push_back(temp);
        }
        
        return ans;
        
    }
};


//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]"
         << endl;
  }
}
// } Driver Code Ends