class Solution {
public:
    void sortColors(vector<int>& arr) {
        int l = 0, r = arr.size() - 1, mid = 0;
        while(mid<=r)
            if(arr[mid] == 0) swap(arr[l++], arr[mid++]);
            else if(arr[mid] == 1) mid++;
            else swap(arr[mid], arr[r--]);
    }
};