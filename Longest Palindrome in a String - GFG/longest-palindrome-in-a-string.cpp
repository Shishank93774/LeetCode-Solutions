//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool pali(const string &str){
        int l = 0, r = str.size() - 1;
        while(l<r) if(str[l++] != str[r--]) return false;
        return true;
    }
    int isPali(const string &str, int len){
        int n = str.size();
        for(int i = 0; i+len<=n; i++)
            if(pali(str.substr(i, len))) return i;
        return -1;
    }
  public:
    string longestPalin (string str) {
        // code here
        int mx = 1, strt = 0;
        for(int parity: {0, 1}){
            int l = 1, r = str.size();
            if(l%2 != parity) l++;
            if(r%2 != parity) r--;
            while(l<=r){
                int mid = l + (r - l)/2;
                if(mid%2 != parity) mid--;
                int v = isPali(str, mid);
                if(v != -1){
                    l = mid + 2;
                    if(mx < mid){
                        mx = mid;
                        strt = v;
                    }
                }else{
                    r = mid - 2;
                }
            }
        }
        return str.substr(strt, mx);
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends