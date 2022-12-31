class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr, vector<int>& brr) {
        int n = arr.size();
        int m = brr.size();
        bool odd = (n+m)%2;
        int md = (n+m)/2;
        if(odd){
            int cnt = 0;
            int i = 0, j = 0;
            while(i<n and j<m){
               if(arr[i]<=brr[j]){
                   i++, cnt++;
                   if(cnt > md){
                       return arr[i-1];
                   }
               }else{
                   j++, cnt++;   
                   if(cnt > md){
                      return brr[j-1];
                   }
               }
            }
            while(i<n){
                i++, cnt++;
                if(cnt > md){
                       return arr[i-1];
                }
            }
            while(j<m){
                j++, cnt++;
                if(cnt > md){
                       return brr[j-1];
                }
            }
        }else{
            int cnt = 0;
            int i = 0, j = 0;
            int a1 = 0, a2 = 0;
            while(i<n and j<m){
               if(arr[i]<=brr[j]){
                   i++, cnt++;
                   if(cnt == md){
                       a1 = arr[i-1];
                   }
                   if(cnt == md+1){
                       a2 = arr[i-1];
                       return (1.0*a1 + a2)/2.0;
                   }
               }else{
                   j++, cnt++;   
                   if(cnt == md){
                       a1 = brr[j-1];
                   }
                   if(cnt == md+1){
                       a2 = brr[j-1];
                       return (1.0*a1 + a2)/2.0;
                   }
               }
            }
            while(i<n){
                i++, cnt++;
                if(cnt == md){
                       a1 = arr[i-1];
                   }
                if(cnt == md+1){
                      a2 = arr[i-1];
                      return (1.0*a1 + a2)/2.0;
                }
            }
            while(j<m){
                j++, cnt++;
                if(cnt == md){
                       a1 = brr[j-1];
                }
                if(cnt == md+1){
                       a2 = brr[j-1];
                       return (1.0*a1 + a2)/2.0;
                }
            }
            return (1.0*a1+a2)/2.0;
        }
        return 0;
    }
};