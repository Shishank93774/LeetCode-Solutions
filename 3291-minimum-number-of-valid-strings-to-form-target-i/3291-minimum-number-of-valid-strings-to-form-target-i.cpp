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
public:
    int minValidStrings(vector<string>& words, string target) {
        int n = target.size();
        
        Trie *tr = new Trie();
        for(const string &s: words)
            tr->add(s);
        
        vector<int> dp(n+1, 1e9);
        
        dp[0] = 0;
        for(int i = 0; i<n; i++){
            TrieNode *cur = tr->root;
            for(int j = i+1; j<=n; j++){
                int idx = target[j-1] - 'a';
                if(cur->children[idx] != NULL){
                    cur = cur->children[idx];
                    dp[j] = min(dp[j], dp[i] + 1);
                }else break;
            }
        }
        
        int ans = dp[n];
        if(ans == 1e9) return -1;
        return ans;
    }
};