class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_set<int> st;
        for(int i = 0; i<n; i++) st.insert(i);
        for(auto e: edges) st.erase(e[1]);
        return vector<int>(st.begin(), st.end());
    }
};