//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string str,int m)
        {
            //code here
            int n = str.size();
            long long ans = 0;
            int f = 1;
            for(int i = n-1; i>=0; i--){
                ans = (ans + 1ll*f*(str[i] - '0'));
                f *= 2;
                f %= m;
                ans %=m;
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
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends