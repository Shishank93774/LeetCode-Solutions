//{ Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}
// } Driver Code Ends


bool findPair(int arr[], int n, int x){
    //code
    unordered_set<int> st;
    for(int i = 0; i<n; i++){
        int cur = arr[i];
        int l = cur - x, r = cur + x;
        if(st.count(l) or st.count(r)) return true;
        st.insert(cur);
    }
    return false;
}