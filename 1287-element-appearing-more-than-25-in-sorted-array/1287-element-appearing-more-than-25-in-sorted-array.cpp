class Solution {
public:
    int findSpecialInteger(const vector<int>& arr) {
        int n = arr.size();
        int quarter = n/4;
        int i = 0;
        while(i<n){
            if(i+quarter<n and arr[i] == arr[i+quarter]) return arr[i];
            i++;
        }
        return -1;
    }
};