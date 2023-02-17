//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the first non-repeating character in a string.
    char nonrepeatingCharacter(string s)
    {
       //Your code here
       
       unordered_map<char, int> map;
       
       for(int i=0; s[i]!='\0'; i++)
       {
           
           map[s[i]]++;
           
       }
       
       char ans='$';
       for(int i=0; s[i]!='\0'; i++)
       {
           if(map[s[i]] == 1)
           {
               ans=s[i];
               break;
           }
       }
       
       return ans;
    }

};

//{ Driver Code Starts.

int main() {
	
	int T;
	cin >> T;
	
	while(T--)
	{
	
	    string S;
	    cin >> S;
	    Solution obj;
        char ans = obj.nonrepeatingCharacter(S);
        
        if(ans != '$')
	    cout << ans;
        else cout << "-1";
            
        cout << endl;
	    
	}
	
	return 0;
}

// } Driver Code Ends