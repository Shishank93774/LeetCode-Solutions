//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class TrieNode{
public:
    char val;
    vector<TrieNode *> children;
    bool isEnd;
    TrieNode(char ch = '$'){
        val = ch;
        children.assign(26, NULL);
        isEnd = false;
    }
};

class Trie{
    TrieNode *root;
public:
    Trie(){
        root = new TrieNode();
    }
    void insert(const string &word){
        int n = word.size(), i = 0;
        TrieNode *ptr = root;
        while(i<n){
            if(ptr->children[word[i] - 'a'] == NULL) ptr->children[word[i] - 'a'] = new TrieNode(word[i] - 'a');
            ptr = ptr->children[word[i] - 'a'];
            i++;
        }
        ptr->isEnd = true;
    }
    bool isPref(const string &word){
        int n = word.size(), i = 0;
        TrieNode *ptr = root;
        while(i<n){
            if(ptr->children[word[i] - 'a'] == NULL) return false;
            ptr = ptr->children[word[i] - 'a'];
            i++;
        }
        return true;
    }
};

class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        // Code here
        Trie t1, t2;
        for(string s: s1) t1.insert(s);
        for(string s: s1) t2.insert(string(s.rbegin(), s.rend()));
        int ans = 0;
        for(string s: s2) ans += (t1.isPref(s) | t2.isPref(string(s.rbegin(), s.rend())));
        return ans;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str1,str2,newline;
        if(i==0)
        getline(cin,newline);
        getline(cin,str1);
        getline(cin,str2);
        // getline(cin,newline);
        // cout<<str1<<endl<<str2<<endl;
        vector<string> s1,s2;
        stringstream ss1(str1);
        stringstream ss2(str2);
        string str;
        while(ss1>>str){
            s1.push_back(str);
        }
        while(ss2>>str){
            s2.push_back(str);
        }
        Solution ob;
        cout<<ob.prefixSuffixString(s1, s2)<<endl;
    }
}
// } Driver Code Ends