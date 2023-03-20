class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        vector<int> ans;
        int n = arr.size();
        vector<bool> left(n, true);
        
        
        vector<int> brr;
        for(int i = 1; i<n; i++) 
            if(arr[i-1] > 0 and arr[i] < 0) 
                brr.push_back(i-1); // Check for Collision.
        
        if(brr.size() == 0) return arr; // Base Case
        
        int r;
        for(int l: brr){
            r = l + 1;
            while(l>=0 and r<n and arr[l] > 0 and arr[r] < 0)
                if(abs(arr[l]) == abs(arr[r])) left[l--] = left[r++] = false;
                else if(abs(arr[l]) < abs(arr[r])) left[l--] = false;
                else left[r++] = false;
        }
        
        for(int i = 0; i<n; i++) if(left[i]) ans.push_back(arr[i]);
        
        return asteroidCollision(ans); // rec
    }
};