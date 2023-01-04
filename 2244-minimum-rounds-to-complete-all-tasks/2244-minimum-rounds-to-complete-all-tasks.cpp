class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int cnt = 0, n = tasks.size();
        unordered_map<int, int> mp;
        for(int x: tasks) mp[x]++;
        for(auto it: mp){
            if(it.second == 1) return -1;
            cnt += ((it.second+2)/3);
        }
        return cnt;
    }
};