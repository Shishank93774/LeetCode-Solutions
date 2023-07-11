//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    Node *reverseLL(Node *head){
        if(head == NULL or head->next == NULL) return head;
        Node *prv = NULL, *cur = head, *nxt;
        do{
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }while(cur);
        
        return prv;
    }
    public:
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        head = reverseLL(head);
        bool c = 1;
        Node* cur = head, *prv;
        while(cur){
            int val = cur->data + c;
            if(val != 10) {cur->data = val; c = 0;}
            else {
                cur->data = 0;
                c = 1;
            }
            prv = cur;
            cur = cur->next;
        }
        if(c == 1){
            Node *newNode = new Node(1);
            prv->next = newNode;
        }
        head = reverseLL(head);
        return head;
    }
};






//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends