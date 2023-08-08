//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

string a, b, c;
int n1, n2, n3;

const int N = 20;
int dp[N][N][N];


int rec(int i, int j, int k){
	if(i == n1 or j == n2 or k == n3) return 0;
	if(dp[i][j][k] != -1) return dp[i][j][k];
	int &ans = dp[i][j][k] = 0;
	if(a[i] == b[j] and b[j] == c[k]){
		ans = 1 + rec(i+1, j+1, k+1);
	}else{
		ans = max({rec(i+1, j, k), rec(i, j+1, k), rec(i, j, k+1)});
		if(a[i] == b[j]){
			ans = max(ans, rec(i+1, j+1, k));
		}else if(b[j] == c[k]){
			ans = max(ans, rec(i, j+1, k+1));
		}else if(c[k] == a[i]){
			ans = max(ans, rec(i+1, j, k+1));
        }
	}
	return ans;
}

int LCSof3 (string A, string B, string C, int nn1, int nn2, int nn3)
{
    // your code here
    a = A, b = B, c = C;
	memset(dp, -1, sizeof dp);
	n1 = A.size(), n2 = B.size(), n3 = C.size();
	return rec(0, 0, 0);
}