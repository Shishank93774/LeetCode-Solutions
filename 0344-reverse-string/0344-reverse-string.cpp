class Solution {
public:
    void reverseString(vector<char>& str) {
        int l = 0, r = str.size()-1;
        while(l<r) swap(str[l++], str[r--]);
    }
};