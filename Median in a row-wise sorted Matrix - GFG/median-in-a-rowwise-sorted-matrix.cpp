//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    int median(vector<vector<int>> &matrix, int n, int m){
        // code here
        auto cntLessEq = [&](vector<int> &arr, int x) ->int{
            int l = 0, r = arr.size() - 1;
            while(l<=r){
                int mid = l + (r - l)/2;
                if(arr[mid] <= x){
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            return l;
        };
        int res = 0;
        int l = 1, r = 2000;
        int req = n*m/2;
        while(l<=r){
            int mid = l + (r - l)/2;
            int cnt = 0;
            for(int i = 0; i<n; i++) cnt += cntLessEq(matrix[i], mid);
            if(cnt <= req){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends