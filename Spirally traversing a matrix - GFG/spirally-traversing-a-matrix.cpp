//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > &arr, int n, int m) 
    {
        // code here 
        vector<int> ans;
        int tr = 0, br = n-1, lc = 0, rc = m-1;
        int r = 0, c = 0; 
        while(true){
            while(c<=rc){
                ans.push_back(arr[r][c++]);
            }
            tr++;
            c--;
            r++;
            if(tr > br) break;
            while(r<=br){
                ans.push_back(arr[r++][c]);
            }
            rc--;
            r--;
            c--;
            if(lc > rc) break;
            while(c>=lc){
                ans.push_back(arr[r][c--]);
            }
            br--;
            c++;
            r--;
            if(tr > br) break;
            while(r>=tr){
                ans.push_back(arr[r--][c]);
            }
            lc++;
            r++;
            c++;
            if(lc > rc) break;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends