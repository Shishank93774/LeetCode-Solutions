class Solution {
public:
    long long numberOfWeeks(vector<int>& arr) {
        long long tot = accumulate(arr.begin(), arr.end(), 0ll), mx = *max_element(arr.begin(), arr.end());
        return min(2*(tot - mx) + 1, tot);
    }
};