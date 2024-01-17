class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        set<int> st;
        map<int, int> mp;
        for(int x: arr) mp[x]++;
        for(auto [k, v]: mp) st.insert(v);
        return (st.size() == mp.size());
    }
};