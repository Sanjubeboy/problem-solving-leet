//{ Driver Code Starts
// Driver function
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string reciprocalString(string s)
    {
        // Write Your code here
        
        string ans = "";
        
        int dis;
        
        for(int i=0; i<s.size(); i++)
        {
            
            if(s[i] >= 'a'  && s[i]<='z')
            {
                
                dis = s[i]-'a';
                ans += 'z'-dis;
                
            }
            
            else if(s[i]>='A' and s[i]<='Z')
            {
                
                dis = s[i] - 'A';
                ans += 'Z' - dis;
                
            }
            
            else
            {
                ans += s[i];
            }
            
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    string S;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        getline(cin,S);
        Solution ob;
        string reciprocal = ob.reciprocalString(S);
        cout<< reciprocal <<endl;

    }

	return 0;
}
// } Driver Code Ends