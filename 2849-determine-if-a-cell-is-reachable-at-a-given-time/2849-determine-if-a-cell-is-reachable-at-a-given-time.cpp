class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx > fx) swap(sx, fx);
        if(sy > fy) swap(sy, fy);
        if(sx == fx and sy == fy and t == 1) return false;
        return (t >= max(fy - sy, fx - sx));
    }
};