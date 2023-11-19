class Solution {
public:
    int reductionOperations(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        int req = 0;
        int prv = arr[0];
        for(int i = 0; i<arr.size(); i++){
            if(arr[i] != prv){
                req++;
                prv = arr[i];
            }
            ans += req;
        }
        return ans;
    }
};