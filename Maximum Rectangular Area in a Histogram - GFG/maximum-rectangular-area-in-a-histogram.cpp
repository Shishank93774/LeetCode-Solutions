//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        vector<long long> nse(n+1), pse(n+1);
        stack<long long> stk;
        for(int i = 0; i<n; i++){
            while(!stk.empty() and arr[stk.top()] >= arr[i]) stk.pop();
            if(stk.empty()) pse[i] = -1;
            else pse[i] = stk.top();
            stk.push(i);
        }
        stk = stack<long long>();
        for(int i = n-1; i>=0; i--){
            while(!stk.empty() and arr[stk.top()] > arr[i]) stk.pop();
            if(stk.empty()) nse[i] = n;
            else nse[i] = stk.top();
            stk.push(i);
        }
        long long ans = arr[0];
        for(int i = 0; i<n; i++) ans = max(ans, arr[i]*(nse[i] - pse[i] - 1));
        return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends