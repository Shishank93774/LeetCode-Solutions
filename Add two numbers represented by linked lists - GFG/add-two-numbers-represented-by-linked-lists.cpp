//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    struct Node* reverseLL(struct Node* head){
        if(head == NULL or head->next == NULL) return head;
        struct Node *cur = head, *prv = NULL, *nxt;
        do{
            nxt = cur->next;
            cur->next = prv;
            prv = cur;
            cur = nxt;
        }while(cur);
        
        return prv;
    }
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        struct Node *head1 = reverseLL(first), *head2 = reverseLL(second);
        int c = 0;
        struct Node *ptr1 = head1, *ptr2 = head2;
        struct Node *head = NULL;
        while(ptr1 and ptr2){
            int sum = ptr1->data + ptr2->data + c;
            struct Node *newNode = new Node(sum%10);
            if(head == NULL) head = newNode;
            else{
                newNode->next = head;
                head = newNode;
            }
            c = sum/10;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        while(ptr1){
            int sum = ptr1->data + c;
            struct Node *newNode = new Node(sum%10);
            if(head == NULL) head = newNode;
            else{
                newNode->next = head;
                head = newNode;
            }
            c = sum/10;
            ptr1 = ptr1->next;
        }
        while(ptr2){
            int sum = ptr2->data + c;
            struct Node *newNode = new Node(sum%10);
            if(head == NULL) head = newNode;
            else{
                newNode->next = head;
                head = newNode;
            }
            c = sum/10;
            ptr2 = ptr2->next;
        }
        if(c){
            struct Node *newNode = new Node(1);
            newNode->next = head;
            head = newNode;
        }
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends