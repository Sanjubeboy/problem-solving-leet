//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	

	vector<int> barcketNumbers(string s)
	{
	    // Your code goes here
	    
	    stack<pair<char,int>> st;
	    vector<int> ans;
	    int t=0;
	    
	    for(int i=0; i<s.size(); i++)
	    {
	        
	        if(s[i] == '(')
	        {
	            t++;
	            st.push({s[i],t});
	            ans.push_back(t);
	        }
	        
	        if(s[i] == ')')
	        {
	            auto temp = st.top();
	            int count = temp.second;
	            st.pop();
	            ans.push_back(count);
	        }
	        
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	string tc;
   	getline(cin, tc);
   	t = stoi(tc);
   	while(t--)
   	{
   		string s;
   		getline(cin, s);

   	    Solution ob;

   		vector<int> ans = ob.barcketNumbers(s);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends