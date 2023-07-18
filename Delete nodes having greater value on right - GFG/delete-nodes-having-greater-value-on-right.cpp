//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    Node* reverseLL(Node *head){
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
    Node *compute(Node *head)
    {
        // your code goes here
        if(head == NULL or head->next == NULL) return head;
        head = reverseLL(head);
        Node *ptr = head;
        while(ptr){
            Node *nxt = ptr->next;
            while(nxt and nxt->data < ptr->data){
                nxt = nxt->next;
            }
            ptr->next = nxt;
            ptr = nxt;
        }
        head = reverseLL(head);
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends