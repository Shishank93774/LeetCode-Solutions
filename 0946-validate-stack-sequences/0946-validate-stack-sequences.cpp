class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        int mp[n+1];
        for(int i = 0; i<n; i++) mp[pushed[i]] = i;
        int ptr = mp[popped[0]];
        pushed[ptr] = -1;
        for(int i = 1; i<n; i++){
            int j = mp[popped[i]];
            if(j > ptr){
                ptr = j;
                pushed[ptr] = -1;
            }else{
                int tptr = ptr;
                while(tptr > j and pushed[tptr] == -1) tptr--;
                if(tptr != j) return false;
                ptr = j;
                pushed[ptr] = -1;
            }
        }
        return true;
    }
};