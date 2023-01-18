class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i = 1, n = arr.size();
        if(n < 3) return false;
        while(i<n and arr[i-1] < arr[i])i++;
        if(i>=n or i == 1) return false;
        while(i<n and arr[i-1] > arr[i])i++;
        return n>=3 and i >= n;
    }
};
