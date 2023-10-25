class Solution {
public:
    int kthGrammar(int n, int k) {
        bool cur = 0;
        int l = 1, r = (1<<n);
        
        while(l<=r){
            int mid = l + (r - l)/2;
            
            if(k <= mid) r = mid - 1;
            else cur = !cur, l = mid + 1;
        }
        
        return cur;
        
    }
};