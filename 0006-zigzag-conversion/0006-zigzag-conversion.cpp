class Solution {
public:
    string convert(string str, int numRows) {
        if(numRows == 1) return str; 
        int n = str.length();
        unordered_map<int, string> mp;
        int cnt = 1, f = 1;
        for(int i = 0; i<n; i++){
            if(cnt == numRows){
                f = -1;
            }
            if(cnt <= 1){
                f = 1;
            }
            mp[cnt] += str[i];
            cnt += f;
        }
        string ans = "";
        for(int i = 1; i<=numRows; i++) ans += mp[i];
        return ans;
    }
};