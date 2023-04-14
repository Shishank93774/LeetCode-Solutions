//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

const int N = 100005 + 12;
int dp[N+1];

class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
      //Your code here
      memset(dp, 0, sizeof dp);
      int mx = arr[0];
      for(int i = 0; i<n; i++) dp[arr[i]] = 1, mx = max(mx, arr[i]);
      int ans = 1;
      for(int i = 1; i<=mx; i++){
          if(dp[i] == 0) continue;
          if(dp[i-1]) dp[i] = dp[i-1] + 1;
          else dp[i] = 1;
          ans = max(dp[i], ans);
      } 
      return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends