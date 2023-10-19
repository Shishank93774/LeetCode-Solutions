class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string word1, word2;
        for(char c: s){
            if(c == '#') {if(!word1.empty()) word1.pop_back();}
            else word1 += c;
        }
        for(char c: t){
            if(c == '#') {if(!word2.empty()) word2.pop_back();}
            else word2 += c;
        }
        return word1 == word2;
    }
};