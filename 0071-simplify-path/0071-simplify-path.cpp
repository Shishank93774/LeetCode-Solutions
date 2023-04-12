class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        vector<string> spl;
        int i = 0;
        string ans = "", tmp = "";
        while(i<path.length()){
            if(path[i] == '/'){
                spl.push_back(tmp);
                tmp = "";
            }else{
                tmp += path[i];
            }
            i++;
        }
        if(tmp.size()) spl.push_back(tmp);
        tmp = "";
        for(int i = 0; i<spl.size(); i++){
            if(!stk.empty() and spl[i] == "..") stk.pop();\
            else if(spl[i] != "" and spl[i] != "." and spl[i] != "..") stk.push(spl[i]);
        }
        if(stk.empty()) return "/";
        while(!stk.empty()){
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};