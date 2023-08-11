class Solution {
public:
    int longestValidParentheses(string str) {
        int open = 0, close = 0;
        int ans = 0, n = str.size();
        for(int i = 0; i<n; i++){
            if(str[i] == '(') open++;
            else close++;
            if(open == close){
                ans = max(ans, 2*open);
            }else if(close > open){
                open = close = 0;
            }
        }
        open = 0, close = 0;
        for(int i = n-1; i>=0; i--){
            if(str[i] == '(') open++;
            else close++;
            if(open == close){
                ans = max(ans, 2*open);
            }else if(close < open){
                open = close = 0;
            }
        }
        
        return ans;
    }
};