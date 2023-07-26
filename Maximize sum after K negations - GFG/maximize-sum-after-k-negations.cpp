//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long arr[], int n, int k)
    {
        // Your code goes here
        sort(arr, arr+n, [](int a, int b){
            return abs(a) < abs(b);
        });
        int neg = 0;
        for(int i = 0; i<n; i++) neg += (arr[i]<0);
        if(neg <= k){
            long long ans = 0;
            if((k-neg)%2){
                ans = min(-arr[0], arr[0]);
            }else{
                ans = max(-arr[0], arr[0]);
            }
            for(int i = 1; i<n; i++){
                ans += abs(arr[i]);
            }
            return ans;
        }else{
            long long ans = 0;
            int i = n-1;
            for(; i>=0 and k; i--){
                ans += abs(arr[i]);
                if(arr[i] < 0) k--;
            }
            for(; i>=0; i--){
                ans += arr[i];
            }
            return ans;
        }
    }
};

//{ Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}
// } Driver Code Ends