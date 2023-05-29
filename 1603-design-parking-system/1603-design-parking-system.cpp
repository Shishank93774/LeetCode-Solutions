class ParkingSystem {
    int caps[4];
    int cur[4];
public:
    ParkingSystem(int big, int medium, int small){
        caps[1] = big, caps[2] = medium, caps[3] = small;
        cur[1] = cur[2] = cur[3] = 0;
    }
    
    bool addCar(int t) {
        if(cur[t] + 1 <= caps[t]) return (++cur[t]);
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */