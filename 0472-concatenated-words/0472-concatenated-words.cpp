class TrieNode{
public:
    TrieNode *children[26];
    bool isEnd;

    TrieNode(){
        for(int i = 0; i<26; i++) children[i] = NULL;
        isEnd = false;
    }
};

class Trie{
public:
    TrieNode *root;
    
    Trie(){
        root = new TrieNode();
    }
    
    void insert(string word){
        TrieNode *node = root;
        for(int i = 0; i<word.length(); i++){
            if(node->children[(word[i] - 'a')] == NULL){
                node->children[(word[i] - 'a')] = new TrieNode();
            }
            node = node->children[(word[i] - 'a')];
        }
        node->isEnd = true;
    }
};

void print(TrieNode *node, string word){
    if(node == NULL) return;
    if(node->isEnd){
        cout<<word<<"\n";
    }
    for(int i = 0; i<26; i++){
        char ch = 'a' + i;
        if(node->children[i] != NULL){
            word.push_back(ch);
            print(node->children[i], word);
            word.pop_back();
        }
    }
}

unordered_set<string> st;


bool rec(Trie *tree, TrieNode *root, string word, int &cnt, int pos = 0){
    if(root == NULL) return false;
    if(pos == word.length()){
        if(cnt > 1) st.insert(word);
    }
    bool chk = true;
    TrieNode *node = root;
    for(int i = pos; i<word.length(); i++){
        if(node->children[word[i]-'a'] == NULL) return false;
        node = node->children[word[i] - 'a'];
        pos++;
        if(node->isEnd){
            cnt++;
            chk &= rec(tree, tree->root, word, cnt, pos);
            cnt--;
        }
    }
    return chk;
}

class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie *tree = new Trie();
        for(auto word: words) tree->insert(word);
        
        // print(tree->root, "");
        
        st.clear();
        
        
        for(auto word: words){
            int cnt = 0;
            rec(tree, tree->root, word, cnt);
        }
        
        vector<string> ans(st.begin(), st.end());

        return ans;
    }
};