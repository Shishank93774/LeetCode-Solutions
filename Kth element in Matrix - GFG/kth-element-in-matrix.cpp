//{ Driver Code Starts
// kth largest element in a 2d array sorted row-wise and column-wise
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);
// driver program to test above function
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
     // cout << "7th smallest element is " << kthSmallest(mat, 4, 7);
      return 0;
}

// } Driver Code Ends



int kthSmallest(int arr[MAX][MAX], int n, int k)
{
  //Your code here
  auto cntLessEq = [&](int arr[], int x) ->int{
      int l = 0, r = n-1;
      int ans = 0;
      while(l<=r){
          int mid = l + (r - l)/2;
          if(arr[mid] <= x){
              ans = mid+1;
              l = mid + 1;
          }else{
              r = mid - 1;
          }
      }
      return ans;
  };
  int l = 1, r = 10004+4;
  int ans = 0;
  while(l<=r){
      int mid = l + (r - l)/2;
      int cnt = 0;
      for(int i = 0; i<n; i++) cnt += cntLessEq(arr[i], mid);
      if(cnt < k){
          l = mid + 1;
      }else{
          ans = mid;
          r = mid - 1;
      }
  }
  return ans;
}
