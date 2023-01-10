class Solution {
public:
    bool canMeasureWater(int a, int b, int t) {
        return (t<=(a+b) and t%(__gcd(a, b)) == 0);
    }
};