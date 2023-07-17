//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

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

class Solution{
    Node* mergeLL(Node *head1, Node *head2){
        if(head1 == NULL) return head2;
        if(head2 == NULL) return head1;
        Node *head = NULL, *tail = NULL;
        while(head1 and head2){
            if(head1->data <= head2->data){
                if(head == NULL){
                    head = tail = head1;
                }else{
                    tail->next = head1;
                    tail = head1;
                }
                head1 = head1->next;
            }else{
                if(head == NULL){
                    head = tail = head2;
                }else{
                    tail->next = head2;
                    tail = head2;
                }
                head2 = head2->next;
            }
        }
        while(head1){
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        while(head2){
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
        return head;
    }
    
    Node* mergeSort(Node *arr[], int l, int r){
        if(l > r) return NULL;
        if(l == r) return arr[l];
        int mid = l + (r - l)/2;
        Node *ll = mergeSort(arr, l, mid);
        Node *rr = mergeSort(arr, mid+1, r);
        return mergeLL(ll, rr);
    }
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int n)
    {
       // Your code here
       int l = 0, r = n - 1;
       return mergeSort(arr, l, r);    
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}

// } Driver Code Ends