unordered_map<int, string> mp;
int n, cnt, f, i;
string ans;
class Solution {
public:
    string convert(string str, int numRows) {
        if(numRows == 1) return str; 
        mp.clear();
        n = str.length(), cnt = 1, f = 1;
        for(i = 0; i<n; i++){
            if(cnt == numRows){
                f = -1;
            }
            if(cnt <= 1){
                f = 1;
            }
            mp[cnt] += str[i];
            cnt += f;
        }
        ans = "";
        for(i = 1; i<=numRows; i++) ans += mp[i];
        return ans;
    }
};