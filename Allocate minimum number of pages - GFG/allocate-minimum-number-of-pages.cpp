//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    bool chk(int arr[], int n, int m, long long x){
        long long sum = 0;
        int i = 0;
        int req = 1;
        while(i<n){
            if(sum + arr[i] <= x){
                sum += arr[i];
            }else{
                sum = arr[i];
                req++;
            }
            i++;
        }
        return (req <= m);
    }
    public:
    //Function to find minimum number of pages.
    int findPages(int arr[], int n, int m) 
    {
        //code here
        long long l = *max_element(arr, arr+n), r = accumulate(arr, arr+n, 0ll);
        if(m == 1) return r;
        if(n == m) return l;
        if(n < m) return -1;
        int ans = -1;
        while(l<=r){
            long long mid = l + (r - l)/2;
            if(chk(arr, n, m, mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends