class Solution {
    bool isPali(string &str){
        int l = 0, r = str.length() - 1;
        while(l<r) if(str[l++] != str[r--]) return false;
        return true;
    }
    void rec(int i, int n, string &str, vector<string> cur, vector<vector<string> > &ans){
        if(i == n){
            ans.push_back(cur);
            return;
        }
        for(int j = i; j<n; j++){
            string s = str.substr(i, j-i+1);
            if(isPali(s)){
                cur.push_back(s);
                rec(j+1, n, str, cur, ans);
                cur.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ans;
        rec(0, s.length(), s, {}, ans);
        return ans;
    }
};