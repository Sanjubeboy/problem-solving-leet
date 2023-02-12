//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};


// } Driver Code Ends
//User function Template for C++

/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:


    int isprime(int n)
    {
        if(n<2)
            return 0;
        if(n==2)
            return 1;
        // if(n%2==0 || n%3==0)
        //     return 0;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
                return 0;
                
        }
        return 1;
    }
    

    Node *primeList(Node *head){
        
        if(head==NULL)
            return head;
        
        Node *temp=head;
        while(temp)
        {
            // if(isprime(temp->val)) continue;
            int k=0;
            
            while(1)
            {
                if(isprime(temp->val-k))
                {
                    temp->val-=k;
                    break;
                }
                if(isprime(temp->val+k))
                {
                    temp->val+=k;
                    break;
                }
                
                k++;
            }
            temp=temp->next;
        }
        
        return head;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        Node *head,*tail;
        int num;
        cin>>num;
        head=tail=new Node(num);
        for(int i=0;i<n-1;i++){
            int num;
            cin>>num;
            tail->next=new Node(num);
            tail=tail->next;
        }
        Solution ob;
        Node *temp=ob.primeList(head);
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends