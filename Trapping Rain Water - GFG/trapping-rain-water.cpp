//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        long long ans = 0;
        int mxIndx = max_element(arr, arr + n) - arr; // max Element's index
        pair<long long, int> cur = {arr[0], 0};// the first value to start with.
        long long extraArea = 0; 
        // stores the extra area which has to be deleted.
        for(int i = 1; i<=mxIndx; i++){ 
            if(arr[i] >= cur.first){ // If I found out value greater than previous one 
                ans += (i - cur.second - 1)*cur.first; // I add the area to my ans.
                ans -= extraArea; // Don't forget to remove the extra area.
                extraArea = 0;
                cur = {arr[i], i}; // Making this maximum element as my current for future calculation.
            }else{
                extraArea += arr[i]; // Keeping track of Extra area.
            }
        }
        vector<int> right;
        for(int i = n-1; i>=mxIndx; i--) right.push_back(arr[i]); 
        cur = {right[0], 0};
        extraArea = 0;
		// Doing the same above stuff again.
        for(int i = 1; i<right.size(); i++){
            if(right[i] >= cur.first){
                ans += (i - cur.second - 1)*cur.first;
                ans -= extraArea;
                extraArea = 0;
                cur = {right[i], i};
            }else{
                extraArea += right[i];
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends