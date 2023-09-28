int deg(char c){
    switch(c){
        case 'I': return 0;
        case 'V': return 1;
        case 'X': return 2;
        case 'L': return 3;
        case 'C': return 4;
        case 'D': return 5;
        case 'M': return 6;
    }
    return -1;
}
int val(char c){
    switch(c){
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
    }
    return 0;
}
class Solution {
public:
    int romanToInt(const string &str) {
        int n = str.size();
        int pdeg = deg(str[n-1]), ans = val(str[n-1]), f = 1, i = n-2;
        while(i>=0){
            if(deg(str[i]) < pdeg) f = -1;
            else if(pdeg < deg(str[i])) f = 1;
            ans += f*val(str[i]);
            pdeg = deg(str[i--]);
        }
        return ans;
    }
};





