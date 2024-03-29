class SeatManager {
    set<int> seats;
public:
    SeatManager(int n) {
        for(int i = 1; i<=n; i++) seats.insert(i);
    }
    
    int reserve() {
        int mn = *seats.begin();
        seats.erase(seats.begin());
        return mn;
    }
    
    void unreserve(int seatNumber) {
        seats.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */