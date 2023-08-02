//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
/*You are required to complete this method*/
    int wildCard(string &s,string &t)
    {
        int n = s.size(), m = t.size();
        vector<bool> down(m+1, false);
        down[m] = true;
        for(int i = n-1; i>=0; i--){
            vector<bool> cur(m+1, false);
           if(s[i] == '*') cur[m] = down[m];
           for(int j = m-1; j>=0; j--){
              cur[j] = false;
              if(s[i] == t[j]) cur[j] = down[j+1];
              else{
                 if(s[i] == '?') cur[j] = down[j+1];
                 else if(s[i] == '*'){
                    for(int k = j; k<=m; k++){
                       cur[j] = cur[j] or down[k];
                       if(cur[j]) break;
                    }
                 }
              }
           }
           down = cur;
        }
        
        return down[0];
    }
};

//{ Driver Code Starts.
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
           string pat,text;
           cin>>pat;
cin.ignore(numeric_limits<streamsize>::max(),'\n');
           cin>>text;
           Solution obj;
           cout<<obj.wildCard(pat,text)<<endl;
   }
}

// } Driver Code Ends