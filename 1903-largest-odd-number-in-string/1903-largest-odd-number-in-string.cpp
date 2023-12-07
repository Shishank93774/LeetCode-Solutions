class Solution {
public:
    string largestOddNumber(const string &str) {
        for(int i = str.size()-1; i>=0; i--){
            if((str[i] - '0')%2) return str.substr(0, i+1);
        }
        return "";
    }
};