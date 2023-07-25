//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Node{
public:
    string data;
    Node *left, *right;
    int freq;
    Node(){
        data = "";
        left = right = NULL;
        freq = 0;
    }
    Node(char ch, int f){
        data = "";
        data += ch;
        left = right = NULL;
        freq = f;
    }
    Node(Node *&l, Node *&r){
        data = "(" + l->data + r->data + ")";
        left = l;
        right = r;
        freq = l->freq + r->freq;
    }
};

struct comp{
    bool operator()(Node *n1, Node *n2){
        return n1->freq > n2->freq;
    }
};

class Solution
{
    void preOrder(const Node* root, vector<string> &ans, string soFar){
        if(root == NULL) return;
        if(root->left == NULL and root->right == NULL){
            ans.push_back(soFar);
            return;
        }
        preOrder(root->left, ans, soFar + "0");
        preOrder(root->right, ans, soFar + "1");
    }
	public:
		vector<string> huffmanCodes(string &str, vector<int> &f, int n)
		{
		    // Code here
		    vector<Node *> arr(n);
		    for(int i = 0; i<str.size(); i++) arr[i] = new Node(str[i], f[i]);
		    
		    priority_queue<Node *, vector<Node *>, comp > pqu(arr.begin(), arr.end());
		    
		    while(pqu.size() > 1){
		        Node *l = pqu.top(); pqu.pop();
		        Node *r = pqu.top(); pqu.pop();
		        Node *root = new Node(l, r);
		        pqu.push(root);
		    }
		    vector<string> ans;
		    Node *root = pqu.top(); pqu.pop();
		    preOrder(root, ans, "");
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}
// } Driver Code Ends