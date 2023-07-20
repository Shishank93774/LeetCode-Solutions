//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



// } Driver Code Ends
//User function Template for C++

/*
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};
*/


class Solution{
    Node* helper(string str, int l, int r){
        if(l > r) return NULL;
        int rt = 0;
        int i = l;
        while(i<=r and str[i] != '(') {
            rt = rt*10 + (str[i++] - '0');
        }
        Node *root = new Node(rt);
        
        int leftSubtreeStart = i+1;
        i++; // i -> (
        int sumParantheses = 1;
        while(i<=r and sumParantheses){
            if(str[i] == '(') sumParantheses++;
            else if(str[i] == ')') sumParantheses--;
            i++;
        }
        root->left = helper(str, leftSubtreeStart, i-2);
        
        // i -> (
        int rightSubtreeStart = i+1;
        sumParantheses = 1;
        while(i<=r and sumParantheses){
            if(str[i] == '(') sumParantheses++;
            else if(str[i] == ')') sumParantheses--;
            i++;
        }
        
        root->right = helper(str, rightSubtreeStart, i-2);
        
        return root;
    }
public:
    // function to construct tree from string
    Node *treeFromString(string str){
        // code here
        return helper(str, 0, str.size() - 1);
    }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends