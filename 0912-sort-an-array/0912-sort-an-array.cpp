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
        mergeSort(arr, l, mid), mergeSort(arr, mid + 1, r); 
        merge(arr, l, mid, r);
    }
    int pivot(vector<int> &arr, int l, int r){
        int p = arr[r], i = l-1, pIdx = l;
        while(i++<r) if(arr[i] < p) swap(arr[i], arr[pIdx++]);
        swap(arr[pIdx], arr[r]);
        return pIdx;
    }
    int randPivot(vector<int> &arr, int l, int r){
        int randomIdx = rand() % (r - l + 1) + l;
        swap(arr[randomIdx], arr[r]);
        return pivot(arr, l, r);
    }
    void quickSort(vector<int> &arr, int l, int r, bool random = false){
        if(l>=r) return;
        int p = random ? randPivot(arr, l, r) : pivot(arr, l, r);
        quickSort(arr, l, p-1, random), quickSort(arr, p+1, r, random);
    }
    void countSort(vector<int> &arr){
        const int MAX = 1e5 + 25, EX = 5*(1e4 + 4);
        vector<int> cnt(MAX, 0);
        for(int x: arr) {
            x += EX; 
            cnt[x]++;
        }
        int idx = 0;
        for(int i = 0; i<MAX; i++){
            int counter = cnt[i], val = i - EX;
            while(counter--){
                arr[idx++] = val;
            }
        }
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // mergeSort(nums, 0, nums.size() - 1); 491ms
        // quickSort(nums, 0, nums.size() - 1); TLE
        // quickSort(nums, 0, nums.size() - 1, true); TLE
        // countSort(nums); 113ms
        
        return nums;
    }
};