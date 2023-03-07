class Solution {
public:
    long long maxRunTime(int k, vector<int>& arr) {
        int n = arr.size();
        long long tot = accumulate(arr.begin(), arr.end(), 0ll);
        priority_queue<int> pqu(arr.begin(), arr.end());
        while(!pqu.empty() and k > 0 and pqu.top() > tot / k){
            tot -= pqu.top(); k--; pqu.pop();
        }
        return tot/k;
    }
};