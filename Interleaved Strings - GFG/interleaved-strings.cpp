//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

const int N = 204+4;
int dp[N][N];
class Solution{
    bool rec(int i, int j, const string &a, const string &b, const string &c){
    	int k = i + j;
    	if(k == c.size()) return true;
    	if(dp[i][j] != -1) return dp[i][j];
    	if(a[i] != c[k] and b[j] != c[k]) return false;
    	int ans = false;
    	if(i<a.size() and a[i] == c[k]){
    		ans |= rec(i+1, j, a, b, c);
    	}
    	if(j<b.size() and b[j] == c[k]){
    		ans |= rec(i, j+1, a, b, c);
    	}
    	return dp[i][j] = ans;
    }
public:
    /*You are required to complete this method */
    bool isInterleave(string a, string b, string c) 
    {
        //Your code here
	    memset(dp, -1, sizeof dp);
	    return rec(0, 0, a, b, c);
    }

};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		Solution obj;
		cout<<obj.isInterleave(a,b,c)<<endl;
	}
	// your code goes here
	return 0;
}
// } Driver Code Ends