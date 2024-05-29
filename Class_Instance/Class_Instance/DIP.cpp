
#define interface struct

interface Vehicle {
protected:
    int max_fuel_;
    int remaining_fuel_;
    int power_;

public:
    Vehicle(int max_fuel) : max_fuel_{ max_fuel }, remaining_fuel_{ max_fuel } {
        
    };
    virtual void Accelerate() = 0;
    virtual void Add_fuel() = 0;
};

class RacingCar : public Vehicle {
public:
    RacingCar(int max_fuel) : Vehicle(max_fuel){
    }

    // Vehicle을(를) 통해 상속됨
    void Accelerate() override  {
        power_++;
        remaining_fuel_--;
    }

    void Add_fuel() override
    {
        remaining_fuel_++;
    }
};

class Pilot {
public:
    void Ride(Vehicle* vehicle) {
        vehicle_ = vehicle;
    }
    void IncreaseSpeed() {
        vehicle_->Accelerate();
    }

private:
    Vehicle* vehicle_;
};