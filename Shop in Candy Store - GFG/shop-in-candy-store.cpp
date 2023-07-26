//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int k)
    {
        // Write Your Code here
        int mnCost = 0;
        sort(candies, candies+n);
        int i = 0, j = n-1;
        while(i<=j){
            mnCost += candies[i];
            int free = 0;
            while(i<j and free < k){
                j--;
                free++;
            }
            i++;
        }
        
        int mxCost = 0;
        reverse(candies, candies+n);
        i = 0, j = n-1;
        while(i<=j){
            mxCost += candies[i];
            int free = 0;
            while(i<j and free < k){
                j--;
                free++;
            }
            i++;
        }
        
        return {mnCost, mxCost};
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends