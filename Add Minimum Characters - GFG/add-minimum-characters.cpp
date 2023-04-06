//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
    bool isPalindrome(const string &str){
        int l = 0, r = str.size() - 1;
        while(l<=r) if(str[l++] != str[r--]) return false;
        return true;
    }
public:
    int addMinChar(string str){
        if(isPalindrome(str)) return 0;
        int n = str.size();
        int r = n - 1;
        while(r>=0){
            if(isPalindrome(str.substr(0, r))) break;
            r--;
        }
        return r == 0? n-1:n-r;
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
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends