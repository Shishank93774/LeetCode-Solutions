class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        unordered_map<int, int> mp;
        int n = pushed.size();
        for(int i = 0; i<n; i++) mp[pushed[i]] = i;
        vector<int> used(n, false); // indx
        int ptr = mp[popped[0]];
        used[ptr] = true;
        for(int i = 1; i<n; i++){
            int j = mp[popped[i]];
            if(j > ptr){
                ptr = j;
                used[ptr] = true;
            }else{
                int tptr = ptr;
                while(tptr > j and used[tptr]) tptr--;
                if(tptr != j) return false;
                ptr = j;
                used[ptr] = true;
            }
        }
        return true;
    }
};