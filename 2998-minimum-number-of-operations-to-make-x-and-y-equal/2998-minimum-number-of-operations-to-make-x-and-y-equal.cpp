class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(y >= x) return y - x;
        queue<int> qu;
        qu.push(x);
        int d = 0;
        set<int> st;
        st.insert(x);
        while(!qu.empty()){
            int sz = qu.size();
            while(sz--){
                int tp = qu.front(); qu.pop();
                if(tp == y) return d;
                if(tp%11 == 0 and st.find(tp/11) == st.end()) qu.push(tp/11), st.insert(tp/11);
                if(tp%5 == 0 and st.find(tp/5) == st.end()) qu.push(tp/5), st.insert(tp/5);
                if(st.find(tp-1) == st.end()) qu.push(tp-1), st.insert(tp-1);
                if(st.find(tp+1) == st.end()) qu.push(tp+1), st.insert(tp+1);
            }
            d++;
        }
        return -1;
    }
};