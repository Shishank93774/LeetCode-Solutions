class Solution {    
    void mergeSort(vector<pair<int, int> > &arr, vector<pair<int, int> > &temp, int l, int r, vector<int> &ans){
        if(l >= r) return;
        
        int mid = l + (r - l)/2;
        mergeSort(arr, temp, l, mid, ans);
        mergeSort(arr, temp, mid+1, r, ans);
        
        int i = l, j = mid + 1;
        int k = l;
        int ex = 0;
        while(i<=mid and j<=r){
            if(arr[i] < arr[j]){
                ans[arr[i].second] += ex;
                temp[k++] = arr[i++];
            }else if(arr[i] > arr[j]){
                temp[k++] = arr[j++];
                ex++;
            }else{
                i++; j++;
            }
        }
        
        while(i<=mid){
            ans[arr[i].second] += ex;
            temp[k++] = arr[i++];
        }
        while(j<=r){
            temp[k++] = arr[j++];
        }
        
        for(int a = l; a<=r; a++) arr[a] = temp[a];

    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int> > arr(n), temp(n);
        for(int i = 0; i<n; i++){
            arr[i] = {nums[i], i};
            temp[i] = {nums[i], i};
        }
        vector<int> ans(n, 0);
        
        mergeSort(arr, temp, 0, n-1, ans);
        
        return ans;
        
    }
};