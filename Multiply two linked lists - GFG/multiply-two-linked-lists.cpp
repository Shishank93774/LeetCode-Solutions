//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
 

/* Linked list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
 
/* Function to create a new Node with given data */
struct Node *newNode(int data)
{
    struct Node *new_Node = new Node(data);
    
    return new_Node;
}
 
 
 Node *reverse(Node **r)
{
    Node *prev =NULL;
    Node *cur = *r;
    Node *nxt;
    while(cur!=NULL)
    {
        nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    *r = prev;
}
/* Function to insert a Node at the beginning of the Doubly Linked List */
void push(struct Node** head_ref, int new_data)
{
    /* allocate Node */
    struct Node* new_Node = newNode(new_data);
 
    /* link the old list off the new Node */
    new_Node->next = (*head_ref);
 
    /* move the head to point to the new Node */
    (*head_ref) = new_Node;
}


void freeList(struct Node *Node)
{
	struct Node* temp;
    while(Node != NULL)
    {

        temp=Node;
        Node = Node->next;
        free(temp);
    }

}

 
/* Multiply contents of two linked lists */
long long  multiplyTwoLists (struct Node* , struct Node*);
 
// A utility function to print a linked list
void printList(struct Node *Node)
{
    while(Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
 
/* Driver program to test above function */
int main(void)
{


   int t,n,m,i,x;
   cin>>t;
   while(t--)
   {

    struct Node* first = NULL;
    struct Node* second = NULL;
	    cin>>n;
	    for(i=0;i<n;i++)
	    {
			cin>>x;
			push(&first, x);
	    }
         cin>>m;
	    for(i=0;i<m;i++)
	    {
			cin>>x;
	    push(&second, x);
	    }

	     reverse(&first);
	     reverse(&second);
		 long long res = multiplyTwoLists(first,second);
	    
	    cout<<res<<endl;
        freeList(first);
        freeList(second);

   }
   return 0;
}

// } Driver Code Ends


/* Linked list node structure
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};*/

/*The method multiplies 
two  linked lists l1 and l2
and returns their product*/

const int mod = 1e9+7;

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

/*You are required to complete this method*/
long long  multiplyTwoLists (Node* head1, Node* head2)
{
  //Your code here
//   return ans;
  head1 = reverseLL(head1);
  head2 = reverseLL(head2);
  Node *ptr1 = head1;
  long long ans = 0;
  long long start = 1;
  while(ptr1){
      Node *ptr2 = head2;
      long long temp = 0;
      long long f = 1;
      int carry = 0;
      while(ptr2){
          int x = ptr1->data, y = ptr2->data;
          long long res = 1ll*x*y + carry;
          carry = res/10;
          res %= 10;
          temp = (temp + (res*f)%mod)%mod;
          f = (f*10)%mod;
          ptr2 = ptr2->next;
      }
      temp = (temp + (carry*f)%mod)%mod;
      ans = (ans + (start*temp)%mod)%mod;
      start = (start*10)%mod;
      ptr1 = ptr1->next;
  }
  return ans;
}