class WordDictionary {
    vector<string> words[26];
    bool match(const string &word, const vector<string> &searchSpace){
        int sz = word.size();
        for(int i = 0; i<searchSpace.size(); i++){
            bool chk = true;
            for(int j = 0; j<sz; j++){
                if(word[j] == '.') continue;
                if(word[j] != searchSpace[i][j]){
                    chk = false; break;
                }
            }
            if(chk) return true;
        }
        return false;
    }
public:    
    void addWord(string word) {
        words[word.size()].push_back(word);
    }
    
    bool search(string word) {
        return match(word, words[word.size()]);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */