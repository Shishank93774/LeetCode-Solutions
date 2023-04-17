//{ Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function template for C++

const int MOD = 1e9 + 7;
int P = 41;
class Solution{
    bool verify(const string &str, int i){
        int n = str.length();
        for(int j = 0; j<=i; j++) if(str[j] != str[n-1-i+j]) return false;
        return true;
    }
  public:		
	int lps(string str) {
	    // Your code goes here
	    int ph = 0, sh = 0, p = 1, n = str.size();
	    int ans = 0;
	    for(int i = 0; i+1<n; i++){
	        ph = ((1ll*ph*P)%MOD + (str[i] - 'a' + 1))%MOD;
	        sh = (sh + (1ll*(str[n-1-i] - 'a' + 1)*p)%MOD)%MOD;
	        p = (1ll*p*P)%MOD;
	        if(ph == sh) ans = i+1;
	    }
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}

// } Driver Code Ends