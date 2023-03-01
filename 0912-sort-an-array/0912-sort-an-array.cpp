class Solution {
    void merge(vector<int> &arr, int l, int mid, int r){
        int i = l, j = mid + 1, k = 0;
        vector<int> tmp(r - l + 2);
        while(i<=mid and j<=r) tmp[k++] = arr[i] <= arr[j] ? arr[i++] : arr[j++];
        while(i<=mid) tmp[k++] = arr[i++];
        while(j<=r) tmp[k++] = arr[j++];
        while(k--) arr[r--] = tmp[k];
    }
    void mergeSort(vector<int> &arr, int l, int r){
        if(l>=r) return;
        int mid = (l + r)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r); 
        merge(arr, l, mid, r);
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);
        return nums;
    }
};