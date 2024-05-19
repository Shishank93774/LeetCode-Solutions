class Solution {
public:
    bool isArraySpecial(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = 1; i<n; i++){
            if(arr[i]%2 == arr[i-1]%2) return false;
        }
        return true;
    }
};