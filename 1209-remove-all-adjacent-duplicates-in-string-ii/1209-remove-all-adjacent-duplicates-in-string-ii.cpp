class Solution {
public:
    string removeDuplicates(string str, int k) {
        vector<pair<char, int> > vec;
        int n = str.size();
        for(int i = 0; i<n; i++){
            if(vec.size() and vec.back().first == str[i]){
                vec.back().second++;
            }else{
                vec.push_back({str[i], 1});
            }
            if(vec.back().second == k){
                vec.pop_back();
            }
        }
        string ans;
        for(auto it: vec){
            string t(it.second, it.first);
            ans += t;
        }
        return ans;
    }
};