const string MAX = "2147483647";
class Solution {
public:
    int nextGreaterElement(int n) {
        string str = to_string(n);
        next_permutation(str.begin(), str.end());
        if(str.size() == MAX.size() and str > MAX) return -1;
        if(str <= to_string(n)) return -1;
        return stoi(str);
    }
};