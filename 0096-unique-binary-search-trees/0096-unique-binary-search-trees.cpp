const int N = 20;
int catalan[N];

class Solution {
public:
    int numTrees(int n) {
        catalan[0] = catalan[1] = 1;
        for(int i = 2; i<=n; i++){
            catalan[i] = 0;
            for(int l = 0; l<i; l++){
                catalan[i] += catalan[l]*catalan[i-1-l];
            }
        }
        return catalan[n];
    }
};