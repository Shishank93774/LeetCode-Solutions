class Solution {
    int req(const string &str, bool s){
        int ans = 0;
        for(char c: str){
            ans += (s != (c&1));
            s = !s;
        }
        return ans;
    }
public:
    int minOperations(string s) {
        return min(req(s, 0), req(s, 1));
    }
};