class ParkingSystem {
    int caps[3], cur[3];
public:
    ParkingSystem(int big, int medium, int small){
        caps[0] = big, caps[1] = medium, caps[2] = small;
        cur[0] = cur[1] = cur[2] = 0;
    }
    
    bool addCar(int t) {
        --t;
        if(cur[t] + 1 <= caps[t]) return (++cur[t]);
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */