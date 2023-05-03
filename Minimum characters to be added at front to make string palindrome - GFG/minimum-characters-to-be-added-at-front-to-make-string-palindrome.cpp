//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int minChar(string str){
        //Write your code here
        int n = str.size();
        string tmp(str.rbegin(), str.rend());
        str += "$" + tmp;
        int sz = str.size();
        int lps[sz];
        lps[0] = 0;
        int i = 1, len = 0;
        while(i<sz){
            if(str[i] == str[len]){
                lps[i++] = ++len; 
            }else{
                if(len != 0){
                    len = lps[len-1];
                }else{
                    lps[i++] = 0;
                }
            }
        }
        return n - lps[sz-1];
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.minChar(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends