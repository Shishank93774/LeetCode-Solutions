class Solution {
public:
    int findPermutationDifference(string s, string t) {
        map<char, int> mp;
        for(int i =0; i<s.size(); i++){
            mp[s[i]] = i;
        }
        int  ans  =0;
        for(int  i  =  0; i<t.size(); i++){
            ans += abs(i-mp[t[i]]);
        }
        return ans;
    }
};