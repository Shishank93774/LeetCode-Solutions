class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &arr, int k) {
        int n = arr.size();
        deque<int> dq;
        for(int i = 0; i<k; i++){
            while(!dq.empty() and arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
        }
        vector<int> ans;
        ans.push_back(arr[dq.front()]);
        for(int i = k; i<n; i++){
            if(!dq.empty() and i - dq.front() >= k) dq.pop_front();
            
            while(!dq.empty() and arr[dq.back()] <= arr[i]) dq.pop_back();
            dq.push_back(i);
            ans.push_back(arr[dq.front()]);
        }
        return ans;
    }
};