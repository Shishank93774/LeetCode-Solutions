//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node* middleLL(Node *head){
    if(head == NULL or head->next == NULL) return head;
    Node *slow = head, *fast = head->next;
    while(fast and fast->next) slow = slow->next, fast = fast->next->next;
    return slow;
}

Node* mergeLL(Node *head1, Node *head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    Node *head = NULL, *tail = NULL;
    while(head1 and head2){
        if(head1->data <= head2->data){
            if(head == NULL){
                head = tail = head1;
            }else{
                tail->bottom = head1;
                tail = head1;
            }
            head1 = head1->bottom;
        }else{
            if(head == NULL){
                head = tail = head2;
            }else{
                tail->bottom = head2;
                tail = head2;
            }
            head2 = head2->bottom;
        }
    }
    while(head1){
        tail->bottom = head1;
        tail = head1;
        head1 = head1->bottom;
    }
    while(head2){
        tail->bottom = head2;
        tail = head2;
        head2 = head2->bottom;
    }
    return head;
}

/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL or root->next == NULL) return root;
   Node *mid = middleLL(root);
   Node *head2 = mid->next;
   mid->next = NULL;
   Node *l = flatten(root), *r = flatten(head2);
   return mergeLL(l, r);
}

