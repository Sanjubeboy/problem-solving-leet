//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for c++
class Solution {
  public:
    string removeChars(string string1, string string2) {
        // code here
        
        int hash[26] = {0};
        
        for(int i=0; i<string2.size(); i++)
        {
            int index = string2[i]-'a';
            hash[index]=1;
        }
        
        string ans="";
        
        for(int i=0; i<string1.size(); i++)
        {
            int index = string1[i]-'a';
            
            if(hash[index] != 1)
            {
                ans += string1[i];
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string string1,string2;
        cin >> string1; 
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1,string2) << endl;
    }
    return 0;
}

// } Driver Code Ends