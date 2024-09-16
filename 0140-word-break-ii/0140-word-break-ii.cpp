struct TrieNode{
    bool isEnd;
    TrieNode* children[26];
    TrieNode(){
        isEnd = false;
        for(int i = 0; i<26; i++) children[i] = NULL;
    }
};

class Trie{
public:
    TrieNode *root;

    Trie(){
        root = new TrieNode();
    }

    void add(const string &str){
        int n = str.size(), i = 0;

        TrieNode *cur = root;        
        while(i<n){
            int idx = str[i] - 'a';
            if(cur->children[idx] == NULL)
                cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
            i++;
        }
        cur->isEnd = true;
    }
};

class Solution {
    Trie *tr;
    void rec(int i, const string &str, int n, vector<string> &ans, string soFar){
        if(i == n){
            soFar.pop_back();
            ans.push_back(soFar);
            return;
        }
        
        TrieNode *cur = tr->root;
        for(int j = i; j<n; j++){
            int idx = str[j] - 'a';
            if(cur->children[idx] == NULL) return;
            cur = cur->children[idx];
            soFar += str[j];
            if(cur->isEnd){
                soFar += " ";
                rec(j+1, str, n, ans, soFar);
                soFar.pop_back();
            }
        }
        
    }
public:
    vector<string> wordBreak(const string &str, vector<string>& words) {
        
        tr = new Trie();
        for(string &s: words)
            tr->add(s);

        vector<string> ans;
        rec(0, str, str.size(), ans, "");
        
        return ans;
    }
};