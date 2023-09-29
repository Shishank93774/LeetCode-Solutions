class Solution {
    bool isPalindrome(const string &str, int l, int r){
        while(l<r) if(str[l++] != str[r--]) return false;
        return true;
    }
    void rec(int i, const string &str, vector<string> &till, vector<vector<string> > &ans){
        if(i == str.size()){
            ans.push_back(till);
            return;
        }
        for(int j = i; j<str.size(); j++){
            if(isPalindrome(str, i, j)){
                till.push_back(str.substr(i, j-i+1));
                rec(j+1, str, till, ans);
                till.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        vector<string> tmp;
        rec(0, s, tmp, ans);
        return ans;
    }
};