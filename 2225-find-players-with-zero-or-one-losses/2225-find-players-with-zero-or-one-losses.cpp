class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int> > ans;
        unordered_set<int> winners, losers;
        set<int> a1, a2;
        for(vector<int> &v: matches){
            int w = v[0], l = v[1];
            if(winners.find(l) != winners.end()){
                a1.erase(l);
            }
            if(losers.find(w) != losers.end()){
                a1.erase(w);
            }else{
                a1.insert(w);
            }
            if(losers.find(l) != losers.end()){
                a2.erase(l);
            }else{
                a2.insert(l);
            }
            winners.insert(w);
            losers.insert(l);
        }
        ans.push_back(vector<int>(a1.begin(), a1.end()));
        ans.push_back(vector<int>(a2.begin(), a2.end()));
        return ans;
    }
};