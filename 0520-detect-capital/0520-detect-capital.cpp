class Solution {
public:
    bool detectCapitalUse(string word) {
        int capCnt = 0;
        for(int i = 0; i<word.size(); i++){
            if('A' <= word[i] and word[i] <= 'Z') capCnt++;
        }
        if(capCnt == word.size() or capCnt == 0) return true;
        if(capCnt > 1 or !('A' <= word[0] and word[0] <= 'Z')) return false;
        return true;
    }
};