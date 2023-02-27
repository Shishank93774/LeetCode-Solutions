/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
    bool isLeaf(vector<vector<int> > &arr, int rx, int ry, int tlx, int tly, int brx, int bry){
        int val = arr[rx][ry];
        
        for(int i = tlx; i<=rx; i++)
            for(int j = tly; j<=ry; j++)
                if(arr[i][j] != val) return false;
        
        for(int i = tlx; i<=rx; i++)
            for(int j = ry+1; j<=bry; j++)
                if(arr[i][j] != val) return false;
        
        for(int i = rx+1; i<=brx; i++)
            for(int j = tly; j<=ry; j++)
                if(arr[i][j] != val) return false;
        
        for(int i = rx+1; i<=brx; i++)
            for(int j = ry+1; j<=bry; j++)
                if(arr[i][j] != val) return false;
        
        return true;
    }
    Node* helper(vector<vector<int> > &arr, int tlx, int tly, int brx, int bry){
        int rootx = (brx+tlx)/2, rooty = (tly+bry)/2;
        Node* newNode = new Node(arr[rootx][rooty], true);
        if(tlx == brx) return newNode;
        if(isLeaf(arr, rootx, rooty, tlx, tly, brx, bry)){
            return newNode;
        }
        newNode->isLeaf = false;
        newNode->topLeft = helper(arr, tlx, tly, rootx, rooty);
        newNode->topRight = helper(arr, tlx, rooty+1, rootx, bry);
        newNode->bottomLeft = helper(arr, rootx+1, tly, brx, rooty);
        newNode->bottomRight = helper(arr, rootx+1, rooty+1, brx, bry);
        return newNode;
    }
    void dfs(Node *root){
        if(root == NULL) return;
        cout<<root->val<<"\n";
        if(!root->isLeaf){
            cout<<"TL: ";
            dfs(root->topLeft);
            cout<<"TR: ";
            dfs(root->topRight);
            cout<<"BL: ";
            dfs(root->bottomLeft);
            cout<<"BR: ";
            dfs(root->bottomRight);
        }
    }
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        Node* root = helper(grid, 0, 0, n-1, n-1);
        // dfs(root);
        return root;
    }
};