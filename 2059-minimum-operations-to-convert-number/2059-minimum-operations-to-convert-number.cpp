class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        int ans = 0;
        queue<int> qu;
        qu.push(start);
        int arr[1001] = {0};
        while(!qu.empty()){
            int sz = qu.size();
            while(sz-- > 0){
                int f = qu.front(); qu.pop();
                if(f == goal) return ans;
                if(f<0 or f>1000 or arr[f]) continue;
                arr[f] = true;
                for(int i = 0; i<nums.size(); i++){
                    int a1 = f+nums[i];
                    int a2 = f-nums[i];
                    int a3 = f^(nums[i]);
                    qu.push(a1);
                    qu.push(a3);
                    qu.push(a2);
                }
            }
            ans++;
        }
        return -1;
    }
};