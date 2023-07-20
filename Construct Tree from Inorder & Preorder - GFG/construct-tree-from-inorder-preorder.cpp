//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    Node* helper(int in[], int pre[], int is, int ie, int ps, int pe, int n){
        if(is > ie) return NULL;
        
        int rootVal = pre[ps];
        
        int separatingIdx = is;
        int toLeft = 0;
        while(separatingIdx <= ie and in[separatingIdx] != rootVal) separatingIdx++, toLeft++;
        
        Node *root = new Node(rootVal);
        
        root->left = helper(in, pre, is, separatingIdx-1, ps+1, ps+toLeft, n);
        root->right = helper(in, pre, separatingIdx+1, ie, ps+toLeft+1, pe, n);
        
        return root;
    }
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        return helper(in, pre, 0, n-1, 0, n-1, n);
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends