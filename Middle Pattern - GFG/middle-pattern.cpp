//{ Driver Code Starts
#include <iostream>
using namespace std;

void printPattern(string s);

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin>>s;
	printPattern(s);
	cout<<endl;
	
}
	
	return 0;
}
// } Driver Code Ends


/*method prints the given pattern in a single line */
void printPattern(string s)
{
   //Your code herekkkk
   
   int n = s.size();
   
//   int k = n/2;
   
   for(int i=0; i<s.size(); i++)
   {
       
       int k = n/2;
       for(int j = 0; j<=i; j++)
       {
           cout<<s[k%n];
           k++;
       }
       cout<<"$ ";
   }
   
}
