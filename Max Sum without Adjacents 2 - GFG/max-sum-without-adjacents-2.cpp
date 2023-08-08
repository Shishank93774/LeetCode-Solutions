//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int findMaxSum(vector<int>& arr){
      //Code Here
      int n = arr.size();
      vector<int> down(3, 0), cur(3, 0);
      for(int i = n-1; i>=0; i--){
          for(int prvCnt : {0, 1, 2}){
              int ans = down[0]; // change color
              if(prvCnt < 2)
              ans = max(ans, arr[i] + down[prvCnt+1]); // same color
              cur[prvCnt] = ans;
          }
          down = cur;
      }
      return down[0];
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends