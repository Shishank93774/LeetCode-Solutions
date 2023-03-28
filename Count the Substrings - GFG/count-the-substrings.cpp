//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string str)
    {
        int ans = 0, n = str.size();
        for(int i = 0; i<n; i++){
            int cntL = 0, cntU = 0;
            for(int j = i; j<n; j++){
                cntL += ('a' <= str[j] and str[j] <= 'z');
                cntU += !('a' <= str[j] and str[j] <= 'z');
                ans += (cntL == cntU);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends