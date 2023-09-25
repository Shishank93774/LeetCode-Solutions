class Solution {
public:
    char findTheDifference(string s, string t) {
        char ch = 0;
        for(char &c: s) ch ^= c;
        for(char &c: t) ch ^= c;
        return ch;
    }
};