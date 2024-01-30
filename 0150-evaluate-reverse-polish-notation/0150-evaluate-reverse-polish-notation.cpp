class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> stk;
        for(auto t: tokens){
            if(t == "+"){
                long op2 = stk.top(); stk.pop();
                long op1 = stk.top(); stk.pop();
                long ans = op1 + op2;
                stk.push(ans);
            }else if(t == "-"){
                long op2 = stk.top(); stk.pop();
                long op1 = stk.top(); stk.pop();
                long ans = op1 - op2;
                stk.push(ans);
            }else if(t == "*"){
                long op2 = stk.top(); stk.pop();
                long op1 = stk.top(); stk.pop();
                long ans = op1 * op2;
                stk.push(ans);
            }else if(t == "/"){
                long op2 = stk.top(); stk.pop();
                long op1 = stk.top(); stk.pop();
                long ans = op1 / op2;
                stk.push(ans);
            }else{
                long num = stol(t);
                stk.push(num);
            }
        }
        return stk.top();
    }
};