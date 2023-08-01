//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int wtlim, int wts[], int vals[], int n) 
    { 
       // Your code here
       vector<int> down(wtlim+1, 0);
       for(int i = n-1; i>=0; i--){
           vector<int> cur(wtlim+1, 0);
           for(int wt = 0; wt<=wtlim; wt++){
               if(wt == 0) cur[wt] = 0;
               else{
                   cur[wt] = down[wt];
                   if(wts[i] <= wt) cur[wt] = max(cur[wt], vals[i] + down[wt - wts[i]]);
               }
           }
           down = cur;
       }
       return down[wtlim];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends