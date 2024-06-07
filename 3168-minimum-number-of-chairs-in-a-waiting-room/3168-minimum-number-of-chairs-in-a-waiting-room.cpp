class Solution {
public:
    int minimumChairs(const string &str) {
        int s = 0, mx = 0;
        for(char c: str){
            s += (c == 'E');
            s -= (c == 'L');
            mx = max(mx, s);
        }
        return mx;
    }
};