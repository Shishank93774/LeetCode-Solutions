class Solution {
    double helper(vector<int> &a, vector<int> b){
        int n = a.size(), m = b.size();
        bool odd = (n+m)%2;
        
        int toLeft = (n+m+1)/2;
        int l = 0, r = n;
        
        while(l<=r){
            int mid1 = l + (r-l)/2;
            int mid2 = toLeft - mid1;
            
            int l1 = INT_MIN, l2 = INT_MIN;
            int r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1-1 >= 0) l1 = a[mid1-1];
            if(mid2-1 >= 0) l2 = b[mid2-1];
            if(mid1<n) r1 = a[mid1];
            if(mid2<m) r2 = b[mid2];
            
            if(l1 <= r2 and l2 <= r1){
                if(odd){
                    return max(l1, l2);
                }
                return 1.0*(max(l1, l2) + min(r1, r2))/2.0;
            }
            if(l1 > r2) r = mid1 - 1;
            else l = mid1 + 1;
        }
        
        return -1;
    }
public:
    double findMedianSortedArrays(vector<int>& arr, vector<int>& brr) {
        int n = arr.size();
        int m = brr.size();
        
        if(n > m) return helper(brr, arr);
        
        return helper(arr, brr);   
    }
};