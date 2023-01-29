class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long ans = 0;
        int n = weights.size();
        priority_queue<int> mxpqu;
        priority_queue<int, vector<int>, greater<int> > mnpqu;
        for(int i = 1; i<n; i++){
            long long s = weights[i] + weights[i-1];
            mnpqu.push(s);
            mxpqu.push(s);
            if(mnpqu.size() == k){
                mnpqu.pop(); mxpqu.pop();
            }
        }
        while(!mxpqu.empty()){
            ans += mnpqu.top() - mxpqu.top();
            mxpqu.pop(); mnpqu.pop();
        }
        return ans;
    }
};