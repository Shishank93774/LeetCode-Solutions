class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i = 0; i<s.length(); i++){
            if(stk.empty() or s[i] == '(' or s[i] == '{' or s[i] == '['){
                stk.push(s[i]);
            }else{
                if(s[i] == ')' and stk.top() == '(') stk.pop();
                else if(s[i] == '}' and stk.top() == '{') stk.pop();
                else if(s[i] == ']' and stk.top() == '[') stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};