// https://leetcode.com/problems/design-ride-sharing-system

class RideSharingSystem {
public:    
    queue<int>rider;
    queue<int>driver;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        vector<int>temp;
        if(!rider.empty() and !driver.empty()){
            temp = {driver.front() , rider.front()};
            rider.pop();
            driver.pop();
        }
        else temp = {-1 , -1};
        return temp;
    }
    
    void cancelRider(int riderId) {
        queue<int>remains;
        while(!rider.empty()){
            int front = rider.front();
            rider.pop();
            if(riderId != front) remains.push(front);
        }
        rider = remains;
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */