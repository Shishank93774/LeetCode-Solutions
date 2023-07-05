//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        int n = str1.size();
        if(n != str2.size()) return false;
        if(unordered_set<char>(str1.begin(), str1.end()).size() != unordered_set<char>(str2.begin(), str2.end()).size()) return false;
        vector<char> mp(26, -1);
        for(int i = 0; i<n; i++){
            if(mp[str1[i]-'a'] != -1 and mp[str1[i]-'a'] != (str2[i] - 'a')) return false;
            mp[str1[i]-'a'] = (str2[i] - 'a');
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends