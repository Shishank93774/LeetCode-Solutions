class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> st;
        for(auto v: paths){
            st.insert(v[1]);
        }
        for(auto v: paths){
            if(st.find(v[0]) != st.end()) st.erase(v[0]);
        }
        return *st.begin();
    }
};