class Solution {
public:
    int search(vector<int>& arr, int x) {
/*         auto pivot = [&]()->int{
         int l = 0, r = arr.size() - 1;
         while(l<=r){
             int mid = l + (r-l)/2;
             if(mid+1< arr.size() and arr[mid] > arr[mid+1]) return mid;
             else if(arr[l] <= arr[mid]) l = mid + 1;
             else r = mid - 1;
         }
         return 0;
     };
  
     auto bs = [&](int l, int r)->int{
         while(l<=r){
             int mid = l + (r-l)/2;
             if(arr[mid] < x) l = mid + 1;
             else if(arr[mid] > x) r = mid - 1;
             else return mid;
         }
         return -1;
     };
     int p = pivot();
     int a1 = bs(0, p), a2 = bs(p+1, arr.size() - 1);
     if(a1 != -1) return a1;
       if(a2 != -1) return a2; 
*/         
    
    int l = 0, r = arr.size() - 1;
    while(l<=r){
        int mid = l + (r - l)/2;
        if(arr[mid] == x) return mid;
        if(arr[l] <= arr[mid]){
            if(arr[l] <= x and x < arr[mid])
                r = mid - 1;
            else l = mid + 1;
        }else{
            if(arr[mid] < x and x <= arr[r])
                l = mid + 1;
            else r = mid - 1;
        }
    }
    return -1;    
    }
};