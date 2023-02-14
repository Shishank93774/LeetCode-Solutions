int n, m, i, c, s;
string ans;

class Solution {
public:
    string addBinary(string a, string b) {
        n = a.size(), m = b.size();
        string padding(abs(n-m), '0');
        n<m?a = padding + a:b = padding + b;
        c = 0, i = max(n, m) - 1;
        ans = "";
        while(i>=0){
            s = c + a[i] - '0' + b[i] - '0';
            ans += (char)('0' + s%2);
            c = s/2;
            i--;
        }
        if(c) ans += "1"; reverse(ans.begin(), ans.end());
        return ans;
    }
};