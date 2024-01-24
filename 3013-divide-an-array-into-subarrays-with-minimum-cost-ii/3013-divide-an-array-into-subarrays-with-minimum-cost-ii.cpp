#define ll long long

class MyStruct{
public:
    MyStruct(int k): k(k), sum(0ll) {};
    int k;
    ll sum;
    multiset<int> mst1, mst2;
    void add(int x){
        mst1.insert(x);
        sum += x;
        if((int)mst1.size() > k){
            auto it = prev(mst1.end());
            mst2.insert(*it);
            sum -= *it;
            mst1.erase(it);
        }
    }
    void rem(int x){
        if(mst2.find(x) != mst2.end()){
            mst2.erase(mst2.find(x));
        }else if(mst1.find(x) != mst1.end()){
            sum -= x;
            auto it = mst1.find(x);
            mst1.erase(it);
            if(mst2.empty()) return;
            it = mst2.begin();
            sum += *it;
            mst1.insert(*it);
            mst2.erase(it);
        }
    }
    
    int size(){
        return (mst1.size() + mst2.size());
    }
};

class Solution {
public:
    ll minimumCost(vector<int>& arr, int k, int dist) {
        ll ans = 6e18;
        k -= 2;
        MyStruct mt(k);
        for(int i = 1; i<(int)arr.size(); i++){
            ll cur = arr[0] + arr[i];
            cur += mt.sum;
            if(mt.size() >= k){
                ans = min(ans, cur);
            }
            mt.add(arr[i]);
            if(i-dist >= 1) mt.rem(arr[i-dist]);
        }
        return ans;
    }
};