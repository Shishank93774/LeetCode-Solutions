class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        while(i>=0 or j>=0){
            int skipI = 0, skipJ = 0;
            while(i>=0){
                if(s[i] == '#') skipI++;
                else if(skipI) skipI--;
                else break;
                i--;
            }
            while(j>=0){
                if(t[j] == '#') skipJ++;
                else if(skipJ) skipJ--;
                else break;
                j--;
            }
            if(i>=0 and j>=0 and s[i] != t[j]) return false;
            if((i>=0) != (j>=0)) return false;
            i--; j--;
        }
        return true;
    }
};