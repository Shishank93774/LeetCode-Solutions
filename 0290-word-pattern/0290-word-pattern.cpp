class Solution {
public:
    bool wordPattern(string pattern, string s) {
        map<string, char> mp;
        map<char, string> mp2;
        vector<string> arr;
        string tmp = "";
        for(char ch: s){
            if(ch != ' ') tmp += ch;
            else {
                arr.push_back(tmp);
                tmp = "";
            }
        }
        arr.push_back(tmp);
        if(arr.size() != pattern.size()) return false;
        for(int i = 0; i<arr.size(); i++){
            if((mp.count(arr[i]) and mp[arr[i]] != pattern[i]) or (mp2.count(pattern[i]) and mp2[pattern[i]] != arr[i])) return false;
            mp[arr[i]] = pattern[i];
            mp2[pattern[i]] = arr[i];
        }
        return true;
    }
};