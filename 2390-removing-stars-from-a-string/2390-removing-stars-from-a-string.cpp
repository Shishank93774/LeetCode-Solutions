class Solution {
public:
    string removeStars(string s) {
        string ans;
        for(char ch: s){
            ans.push_back(ch);
            if(ch == '*') ans.pop_back(), ans.pop_back();
        }
        return ans;
    }
};