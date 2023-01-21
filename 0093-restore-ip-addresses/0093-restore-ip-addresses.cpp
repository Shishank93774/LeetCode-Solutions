class Solution {
    bool verify(const string &str){
        int i = 0, n = str.length();
        long long val;
        string tmp = "", ref;
        while(i<n){
            if(str[i] == '.'){
                if(tmp.length() == 0) return false; // ..
                val = stoll(tmp);
                ref = to_string(val);
                if(val > 255 or ref != tmp) return false;       // 256 or "0"12           
                tmp = "";
            }else{
                tmp += str[i];
            }
            i++;
        }
        if(tmp.length() == 0) return false; // ..
        val = stoll(tmp);
        ref = to_string(val);
        if(val > 255 or ref != tmp) return false; 
        return true;
    }
    void rec(int i, int n, const string &str, string cur, set<string> &ans, int dotsLeft){
        if(i == n){
            if(dotsLeft == 0 and verify(cur)) ans.insert(cur);
            return;
        }
        rec(i+1, n, str, cur + str[i], ans, dotsLeft);
        if(dotsLeft > 0) rec(i+1, n, str, cur + "." + str[i], ans, dotsLeft-1);
    }
public:
    vector<string> restoreIpAddresses(string str) {
        set<string> a1;
        string cur = "";
        cur += str[0];
        rec(1, str.length(), str, cur, a1, 3);
        vector<string> ans;
        for(string str: a1) ans.push_back(str);
        return ans;
    }
};