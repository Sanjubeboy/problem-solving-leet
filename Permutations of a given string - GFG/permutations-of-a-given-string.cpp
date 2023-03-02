//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    
	
	    void helper(int ind, int prev,string s, string temp, set<string> &ans, vector<int> &vis)
	    {
	        
	        if(ind == s.size())
	        {
	            ans.insert(temp);
	            return;
	        }
	        
	        for(int i = 0;  i<s.size(); i++)
	        {
	            
	            if(!vis[i])  
	           {
	               vis[i] = 1;
    	            temp += s[i];
    	            helper(ind+1,i, s, temp, ans, vis);
    	            temp.pop_back();
    	            
    	            vis[i] = 0;
	           }
	            
	        }
	        
	    }
	
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    vector<int> vis(s.size(),0);
		    set<string> ans;
		    vector<string> ret;
		    sort(s.begin(),s.end());
		    
		    string temp="";
		    
		    
		    helper(0,-1,s,temp,ans,vis);
		    
		    ret.insert(ret.end(),ans.begin(),ans.end());
		    
		    return ret;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends