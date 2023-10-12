/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
    int bsInc(vector<int> &cache, MountainArray &mountainArr, int l, int r, int x){
        while(l<=r){
            int mid = l + (r - l)/2;
            int cur = cache[mid];
            if(cur == -1) cur = cache[mid] = mountainArr.get(mid);
            if(cur < x) l = mid + 1;
            else if(cur > x) r = mid - 1;
            else return mid;
        }
        return -1;
    }
    int bsDec(vector<int> &cache, MountainArray &mountainArr, int l, int r, int x){
        while(l<=r){
            int mid = l + (r - l)/2;
            int cur = cache[mid];
            if(cur == -1) cur = cache[mid] = mountainArr.get(mid);
            if(cur < x) r = mid - 1;
            else if(cur > x) l = mid + 1;
            else return mid;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        if(n == 1){
            if(mountainArr.get(0) == target) return 0;
            return -1;
        }
        vector<int> cache(n, -1);
        if(mountainArr.get(0) > mountainArr.get(1)){
            return bsDec(cache, mountainArr, 0, n-1, target);
        }
        if(mountainArr.get(n-1) > mountainArr.get(n-2)){
            return bsInc(cache, mountainArr, 0, n-1, target);
        }
        int l = 1, r = n - 2;
        
        
        int peak = -1;
        
        while(l <= r){
            int mid = l + (r - l)/2;
            int left = cache[mid-1], cur = cache[mid], right = cache[mid+1];
            
            if(left == -1) left = cache[mid-1] = mountainArr.get(mid-1);
            if(cur == -1) cur = cache[mid] = mountainArr.get(mid);
            if(right == -1) right = cache[mid+1] = mountainArr.get(mid+1);
            
            if(left < cur and cur > right){
                peak = mid;
                break;
            }
            if(left < cur) l = mid + 1;
            else r = mid - 1;    
        }
        
        int q1 = bsInc(cache, mountainArr, 0, peak, target);
        if(q1 == -1) return bsDec(cache, mountainArr, peak+1, n-1, target);
        return q1;
    }
};









