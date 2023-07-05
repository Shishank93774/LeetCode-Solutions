//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {
        int cand = arr[0];
        int cnt = 1;
        for(int i = 1; i<n; i++){
            if(arr[i] == cand) cnt++;
            else cnt--;
            if(cnt == 0) {cand = arr[i]; cnt = 1;}
        }
        cnt = 0;
        for(int i = 0; i<n; i++) if(arr[i] == cand) cnt++;
        if(cnt > n/2) return cand;
        return -1;
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends