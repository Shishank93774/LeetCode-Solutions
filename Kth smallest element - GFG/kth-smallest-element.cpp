//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int pivot(int arr[], int l, int r){
        int ele = arr[r], pIdx = l;
        while(l<r){
            if(arr[l] < ele){
                swap(arr[pIdx++], arr[l]);
            }
            l++;
        }
        swap(arr[r], arr[pIdx]);
        return pIdx;
    }
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        int p = pivot(arr, l, r);
        if(p < k-1){
            return kthSmallest(arr, p+1, r, k);
        }else if(p > k-1){
            return kthSmallest(arr, l, p-1, k);
        }
        return arr[p];
    }
};

//{ Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends