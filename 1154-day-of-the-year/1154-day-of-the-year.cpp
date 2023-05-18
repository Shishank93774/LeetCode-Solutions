int ex[13] = {0,0,31,59,90,120,151,181,212,243,273,304,334};
class Solution {
public:
    int dayOfYear(string date) {
        int y = stoi(date.substr(0, 4)), m = stoi(date.substr(5, 2)), d = stoi(date.substr(8));
        if((y%4==0) and ((y%400==0) or y%100) and m>2) d++;
        return ex[m]+d;
    }
};