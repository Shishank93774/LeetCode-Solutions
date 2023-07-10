class Solution {
    void merge(vector<int> &arr, int l, int md, int r){
        // int gap = (r - l + 1);
        // for(; gap >=1; gap /= 2){
        //     for(int i = l + gap; i<=r; i++){
        //         int j = i;
        //         while(j >= gap and arr[j] < arr[j-gap]){
        //             swap(arr[j], arr[j-gap]);
        //             j -= gap;
        //         }
        //     }
        // }
        vector<int> t;
        int i = l, j = md+1;
        while(i<=md and j<=r)
            if(arr[i]<=arr[j])
                t.push_back(arr[i++]);
            else
                t.push_back(arr[j++]);
        while(i<=md) t.push_back(arr[i++]);
        while(j<=r) t.push_back(arr[j++]);
        for(int i = l, k = 0; i<=r; i++, k++) arr[i] = t[k];
    }
    
    void mergeSort(vector<int> &arr, int l, int r){
        if(l>=r) return;
        int mid = l + (r - l)/2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
public:
    vector<int> sortArray(vector<int>& arr) {
        mergeSort(arr, 0, arr.size() - 1);
        return arr;
    }
};