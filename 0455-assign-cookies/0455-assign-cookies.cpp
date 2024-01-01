class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int ans = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, n = g.size(), m = s.size();
        while(i<n and j++<m) if(g[i] <= s[j-1]) i++;
        return i;
    }
};