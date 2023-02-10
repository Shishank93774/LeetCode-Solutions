class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> nge(n);
        stack<int> stk;
        int i = n-2, j = n-1;
        while(i>=0){
            while(!stk.empty() and arr[stk.top()] <= arr[i]) stk.pop();
            stk.push(i);
            i--;
        }
        i = n-1;
        bool f = true;
        while(i>=0){
            while(!stk.empty() and arr[stk.top()] <= arr[i]) stk.pop();
            if(stk.size() == 0){
                nge[i] = -1;
            }else{
                nge[i] = arr[stk.top()];
            }
            stk.push(i);
            i--;
        }
        return nge;
    }
};