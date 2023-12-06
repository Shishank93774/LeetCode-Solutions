class Solution {
public:
    int totalMoney(int n) {
        int cntMondays = n/7;
        int sum = cntMondays*(56 + (cntMondays-1)*7)/2.0;
        int rem = n%7;
        sum += rem*(2*(cntMondays+1) + (rem-1))/2.0;
        return sum;
    }
};