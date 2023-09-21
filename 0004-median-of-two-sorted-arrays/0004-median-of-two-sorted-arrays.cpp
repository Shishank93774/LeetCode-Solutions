class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if(n > m) return findMedianSortedArrays(b, a);
        bool odd = (n+m)%2;
        
        int toLeft = (n+m+1)/2, l = 0, r = n, mid1, mid2, l1, l2, r1, r2;
        
        while(l<=r){
            mid1 = l + (r-l)/2;
            mid2 = toLeft - mid1;
            
            l1 = INT_MIN, l2 = INT_MIN;
            r1 = INT_MAX, r2 = INT_MAX;
            
            if(mid1-1 >= 0) l1 = a[mid1-1];
            if(mid2-1 >= 0) l2 = b[mid2-1];
            if(mid1<n) r1 = a[mid1];
            if(mid2<m) r2 = b[mid2];
            
            if(l1 <= r2 and l2 <= r1){
                if(odd) return max(l1, l2);
                return 1.0*(max(l1, l2) + min(r1, r2))/2.0;
            }
            if(l1 > r2) r = mid1 - 1;
            else l = mid1 + 1;
        }
        
        return -1; 
    }
};