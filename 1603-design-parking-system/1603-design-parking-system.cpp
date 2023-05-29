class ParkingSystem {
    vector<int> rem;
public:
    ParkingSystem(int big, int medium, int small){rem = {big, medium, small};}
    bool addCar(int t) { return rem[--t] > 0 ? rem[t]-- : 0;}
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */