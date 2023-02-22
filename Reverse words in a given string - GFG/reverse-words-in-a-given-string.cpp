//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here
        
        string ans="";
        string temp="";
        stack<string> st;
        
        for(int i=0; i<s.size(); i++)
        {
            if(i == s.size()-1)
            {
                temp += s[i];
                st.push(temp);
            }
            
            if(s[i] == '.' )
            {
                st.push(temp);
                st.push(".");
                temp = "";
            }
            else
            {
                temp += s[i];
            }
            
            
        }
        
        while(!st.empty())
        {
            auto t = st.top();
            st.pop();
            
            ans += t;
            
            
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
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends