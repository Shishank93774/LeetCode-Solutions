//{ Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<int> pref(1441, 0);
    	for(int i = 0; i<n; i++){
    	    int u = arr[i]/100*60+(arr[i]%100), v = dep[i]/100*60+(dep[i]%100);
    	    pref[u]++;
    	    pref[v+1]--;
    	}
    	int mx = 0;
    	for(int i = 0; i<=1440; i++){
    	    pref[i] += i==0?0:pref[i-1];
    	}
    	for(int i = 0; i<=1440; i++) mx = max(mx, pref[i]);
    	return mx;
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}
// } Driver Code Ends