//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long solve(int X,int Y,string str){
      //code here
      int n = str.size();
      stack<char> stk;
      int i = 0;
      long long a1 = 0;
      string left = "";
      while(i<n){
          if(!stk.empty() and stk.top() == 'r' and str[i] == 'p'){
              a1 += Y;
              if(left.size()) left.pop_back();
              stk.pop();
          }else{
              stk.push(str[i]);
              left += str[i];
          }
          i++;
      }
      n = left.size();
      i = 0;
      stk = stack<char> ();
      while(i<n){
          if(!stk.empty() and stk.top() == 'p' and left[i] == 'r'){
              a1 += X;
              stk.pop();
          }else{
              stk.push(left[i]);
          }
          i++;
      }
      
      n = str.size(); i = 0;
      long long a2 = 0;
      left = "";
      stk = stack<char> ();
      while(i<n){
          if(!stk.empty() and stk.top() == 'p' and str[i] == 'r'){
              a2 += X;
              if(left.size()) left.pop_back();
              stk.pop();
          }else{
              stk.push(str[i]);
              left += str[i];
          }
          i++;
      }
      n = left.size();
      i = 0;
      stk = stack<char> ();
      while(i<n){
          if(!stk.empty() and stk.top() == 'r' and left[i] == 'p'){
              a2 += Y;
              stk.pop();
          }else{
              stk.push(left[i]);
          }
          i++;
      }
      
      return max(a1, a2);
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends