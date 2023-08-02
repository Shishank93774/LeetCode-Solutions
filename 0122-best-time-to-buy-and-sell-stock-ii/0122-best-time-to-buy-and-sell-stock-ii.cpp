class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int prv0 = 0, prv1 = 0, cur0, cur1;
        for(int i = arr.size()-1; i>=0; i--){
            cur0 = max(prv0, prv1 - arr[i]);
            cur1 = max(prv1, prv0 + arr[i]);
            prv0 = cur0, prv1 = cur1;
        }
    
        return prv0;
    }
};