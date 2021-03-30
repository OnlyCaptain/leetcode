#include <iostream>
using namespace std;
class ParkingSystem {
private:
    int big;
    int medium;
    int small;
public:
    ParkingSystem(int big, int medium, int small):big(big),medium(medium),small(small) {
        
    }
    
    bool addCar(int carType) {
        switch(carType) {
            case 1: 
                if (big <= 0) return false;
                big --;
                break;
            case 2:
                if (medium <= 0) return false;
                medium --;
                break;
            case 3:
                if (small <= 0) return false;
                small --;
                break;
            default:
                cout << "Error" << endl;
                return false;
        }
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */
int main() {

}